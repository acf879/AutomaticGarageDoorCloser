#include "freertos/task.h"
#include <string.h>
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"

#ifndef AutomaticGarageDoorCloser_h
#define AutomaticGarageDoorCloser_h

#define MAX_STACK_SIZE 4096

#define DEFAULT_SCAN_LIST_SIZE 20

#define DOOR_OPEN 1
#define DOOR_CLOSED 0

#define BEACON_INTERVAL 1000
#define DOOR_SENSOR_INTERVAL 1000
#define WEBSERVER_INTERVAL 1000

TaskHandle_t xHandleWebserverTask;
TaskHandle_t xHandleDoorSensorTask;
TaskHandle_t xHandleBeaconTask;

void initialization(void);
void gpioSetup(void);
void taskSetup(void);

void createWebserverTask(void);
void createDoorSensorTask(void);
void createBeaconTask(void);

void WebserverTask(void *pvParameters);
void DoorSensorTask(void *pvParameters);
void BeaconTask(void *pvParameters);

void wifi_init(void);
static void wifi_scan(void);

#endif