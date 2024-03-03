#include <stdio.h>
#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
#include "AutomaticGarageDoorCloser.h"

void app_main(void)
{
    initialization();
    for (;;)
    {
        // Do something
        printf("Main\n");
    }
}

void initialization(void)
{
    printf("Initializing...\n");
    gpioSetup();
    taskSetup();
    vTaskDelete(NULL); // Delete the initial task
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
    createDoorSensorTask();
    createWebserverTask();
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
    xTaskCreatePinnedToCore(
        DoorSensorTask, 
        "Door Sensor Task", 
        MAX_STACK_SIZE, 
        NULL, 
        2, 
        &xHandleDoorSensorTask, 
        1
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
            printf("Door status\n");
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}

void createBeaconTask(void)
{
    printf("Creating beacon task...\n");
    // Create beacon task
    xTaskCreatePinnedToCore(
        BeaconTask, 
        "Beacon Task", 
        MAX_STACK_SIZE, 
        NULL, 
        1, 
        &xHandleBeaconTask, 
        0
    );
}

void BeaconTask(void *pvParameters)
{
    printf("Beacon task running...\n");
    uint32_t beaconTimer = 0;
    for (;;)
    {
        beaconTimer++;
        // Do something
        if (beaconTimer == BEACON_INTERVAL) {
            printf("Beacon\n");
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}