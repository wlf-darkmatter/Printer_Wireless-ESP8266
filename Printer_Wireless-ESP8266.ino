/*
 Name:		ESP8266_PrinterWireless.ino
 Created:	2020/7/16 18:03:27
 Author:	wlf_x
*/
#include <esp8266_wlf.h>
#include <ESP8266WiFi.h>

//固件中通信与串口默认为115200
const char* ssid = "WLF-printer_WiFi";
const char* pass = NULL;
bool autoConnect = false;



void setup() {
	u8 times = 0;
	Serial.begin(74880);//ESP8266模块上电时，默认打印波特率为74880

	WiFi.setAutoConnect(autoConnect);//启用自动连接。

	delay(1000);
	WiFi.mode(WIFI_AP);//设置WiFi模式

//	Serial.print("\n正在连接到");
//	WiFi.begin(ssid, pass);//连接路由器
    Serial.print("设置接入点中 ... ");
    WiFi.softAP(ssid, pass,1,0,4);//WiFi.softAP(名称, 密码, 信道, 是否隐藏-0:否;1:是, 最大连接数<=4)

    Serial.println("");              // 通过串口监视器输出信息
    Serial.print("当前工作模式:");     // 告知用户设备当前工作模式
    Serial.println(WiFi.getMode());
    Serial.print("接入点名字:");
    Serial.println(ssid);         // 告知用户建立的接入点WiFi名
    Serial.print("接入点密码:");
    Serial.println(pass);        // 告知用户建立的接入点WiFi密码
/*	while ((WiFi.status() != WL_CONNECTED) && times < 30) {//等待WiFi连接
		delay(500);
		times++;
		Serial.print(".");
	}
	if (times >= 30) Serial.print("\n连接超时。");
*/
	Serial.print("当前模式为： ");     // 通过串口监视器输出信息
	Serial.println(WiFi.getMode());  // 告知用户设备当前工作模式

	delay(5000);//延时便于查看效果

	/*   Serial.println("同步扫描开始");
	int n = WiFi.scanNetworks();    //开始同步扫描，将返回值
	Serial.println("同步扫描结束");   //存放在变量n中
	if (n == 0) {
	Serial.println("找不到网络");
	}
	else {
	Serial.println("发现网络");
	for (int i = 0; i < n; ++i) {  //开始逐个打印扫描到的
	Serial.print(i + 1);        //接入点信息
	Serial.print(": ");
	//打印wifi账号
	Serial.print(WiFi.SSID(i));
	//打印该接入点信道
	Serial.print(String(",   WIFI信道:") + WiFi.channel(i));
	Serial.print(",   是否隐藏：");
	//打印该接入点是否隐藏
	Serial.print(WiFi.isHidden(i) ? "隐藏" : "显示");
	Serial.print(",   信号强度：");
	//打印wifi信号强度
	Serial.print(WiFi.RSSI(i));
	Serial.print("dBm");
	Serial.print(",   是否加密：");
	//打印wifi加密方式
	Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? "开放" : "加密");
	delay(10);
	}
	}
	Serial.println("");
	*/
	Serial.begin(74880);
	pinMode(D1,INPUT);
	pinMode(D2,INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	
}
