/*
 Name:		ESP8266_PrinterWireless.ino
 Created:	2020/7/16 18:03:27
 Author:	wlf_x
*/
#include <ESP8266WiFi.h>
//ESP8266模块上电时，默认打印波特率为74880
//固件中通信与串口默认为115200
const char* ssid = "东南沿海王大哥";
const char* pass = "19981213";

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);//设置WiFi模式
    WiFi.begin(ssid, pass);//连接路由器
    Serial.print("正在连接到");
    Serial.print(ssid);
    Serial.print("\rOK\r");
    
}

// the loop function runs over and over again until power down or reset
void loop() {
    Serial.print("\rOK\r");
    delay(100);
}
