#include <dht11.h>
#include <IRremoteInt.h>
#include <IRremote.h>

#define DHT11PIN 2                                  //dht11数据端使用引脚2

String val = "";                                    //val用来存储传过来的数值，为String类型

String temp = "O";
String temp1 = "C";

IRsend irsend;                                      //红外发送
dht11 DHT11;
 
void setup()  
{  
  Serial.begin(115200);
  
}  
  
void loop()  
{  
  /*                                                 //切换到mySerival串口
   int temp = DHT11.read(DHT11PIN);                  //temp用来记录pin2口读取到的成功情况
 //判断dht11传感器读取数据是否成功
  mySerial.print("Read Result: ");
 switch (temp)
  {
    case DHTLIB_OK:                                 //三种情况在dht11头文件中是有定义的
                mySerial.println("OK");              //返回的值是0
                break;
    case DHTLIB_ERROR_CHECKSUM:                    //返回的值是-1
                mySerial.println("Checksum error"); 
                break;
    case DHTLIB_ERROR_TIMEOUT:                      //返回的值是-2
                mySerial.println("Time out error"); 
                break;
    default: 
                mySerial.println("Unknown error"); 
                break;
  } 
   //在串口打印出温湿度
  mySerial.print("Humidity (%): ");
  mySerial.println((float)DHT11.humidity, 2);       //dht11类中的变量humdidity（湿度）

  mySerial.print("Temperature (oC): ");
  mySerial.println((float)DHT11.temperature, 2);    //dut11类中的变量temperature（温度）
  
  delay(2000);                                     
  mySerial.println(); 

  
*/  
  
  if(val.length() > 0)                              //将val清空
  {
     val = "";
  }
 
  while(Serial.available() > 0)
  {
    val += char(Serial.read());                     //一个个字符的连接                     
    delay(2);                                       
  }
  
  
  if(val == temp)//判断接收到的指令或字符是否是“R”。  
  {//如果接收到的是“O”字符  
    Serial.println("The Air is open");
   
      irsend.sendMIDEA(0x1FE008F7, 32); 
      irsend.sendMIDEA(0x1FE008F7, 32); 
      delay(500);
  }  
  if(val == temp1)
  {
      Serial.println("The Air is close");
 
      irsend.sendMIDEA(0x7B84E01F, 32); 
      irsend.sendMIDEA(0x7B84E01F, 32); 
  }

 
}




/*


关闭 0x7B84E01F
摆风 0x6B94E01F
强劲 0xF50AA25D
清新 0xF50AA35C
数显 0xF50AA55A
风向 0x1FE044BB






*/
