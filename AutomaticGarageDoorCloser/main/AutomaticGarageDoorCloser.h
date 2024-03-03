#include "freertos/task.h"

#ifndef AutomaticGarageDoorCloser_h
#define AutomaticGarageDoorCloser_h

#define MAX_STACK_SIZE 4096

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

#endif