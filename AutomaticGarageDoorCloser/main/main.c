#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "AutomaticGarageDoorCloser.h"
#include "esp_wifi.h"
#include "esp_task_wdt.h"

void app_main(void)
{
    initialization();
    for (;;)
    {
        // Do something
        wifi_scan();
    }
}

void initialization(void)
{
    printf("Initializing...\n");
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );
    wifi_init();
    gpioSetup();
    //taskSetup();
    //vTaskDelete(NULL); // Delete the initial task
}

void gpioSetup(void)
{
    printf("Setting up GPIO...\n");
    // Set up GPIO
}

void taskSetup(void)
{
    printf("Setting up tasks...\n");
    createBeaconTask();
    //createDoorSensorTask();
    //createWebserverTask();
    printf("Tasks all set up.\n");
}

void createWebserverTask(void)
{
    printf("Creating webserver task...\n");
    // Create webserver task
    xTaskCreate(
        WebserverTask, 
        "Webserver Task", 
        MAX_STACK_SIZE, 
        NULL, 
        5, 
        &xHandleWebserverTask
    );
}

void WebserverTask(void *pvParameters)
{
    printf("Webserver task running...\n");
    for (;;)
    {
        uint32_t webServerTimer = 0;
        if (webServerTimer == WEBSERVER_INTERVAL) {
            printf("Webserver\n");
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}

void createDoorSensorTask(void)
{
    printf("Creating door sensor task...\n");
    // Create door sensor task
    xTaskCreate(
        DoorSensorTask, 
        "DoorSensor Task", 
        MAX_STACK_SIZE, 
        NULL, 
        1, 
        &xHandleDoorSensorTask
    );
}

void DoorSensorTask(void *pvParameters)
{
    uint32_t doorTimer = 0;
    printf("Door sensor task running...\n");
    for (;;)
    {
        doorTimer++;
        // Do something
        if (doorTimer == DOOR_SENSOR_INTERVAL) {
            
            doorTimer = 0;
        }
    }
}

void createBeaconTask(void)
{
    printf("Creating beacon task...\n");
    // Create beacon task
    xTaskCreate(
        BeaconTask, 
        "Beacon Task", 
        MAX_STACK_SIZE, 
        NULL, 
        2, 
        &xHandleBeaconTask
    );
}

void BeaconTask(void *pvParameters)
{

    printf("Beacon task running...\n");
    uint32_t beaconTimer = 0;

    for (;;) {
        beaconTimer++;
        // Do something
        if (beaconTimer == BEACON_INTERVAL) {
            printf("Beacon\n");
            wifi_scan();
        }
    }
}

void wifi_init(void) {
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());
}

void wifi_scan(void) {
    uint16_t ap_count = 0;
    uint16_t number = DEFAULT_SCAN_LIST_SIZE;
    wifi_ap_record_t ap_info[DEFAULT_SCAN_LIST_SIZE];

    esp_wifi_scan_start(NULL, true);
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&number, ap_info));
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_count));
    printf("Total APs scanned = %u\n", ap_count);
    for (int i = 0; (i < DEFAULT_SCAN_LIST_SIZE) && (i < ap_count); i++) {
        printf("SSID \t\t%s", ap_info[i].ssid);
        printf("RSSI \t\t%d", ap_info[i].rssi);
        printf("BSSID \t\t%02X%02X%02X%02X%02X%02X\n", 
            ap_info[i].bssid[0], ap_info[i].bssid[1], ap_info[i].bssid[2], 
            ap_info[i].bssid[3], ap_info[i].bssid[4], ap_info[i].bssid[5]);
    }
}