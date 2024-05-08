/*
  このArduinoコードは、土壌水分センサーを用いた自動水やりシステムを制御するために設計されています。
  土壌の水分が設定した閾値を下回ると、システムは水ポンプを起動します。

  ボード: Arduino Uno R4 (または R3)
  コンポーネント: 容量性土壌水分センサーおよび水ポンプ
*/

// 水ポンプのピン設定
const int pump1A = 9;  // ポンプ制御用ピン
const int pump1B = 10; // ポンプ制御用ピン（未使用）
bool pumpStatus = false;  // ポンプの状態（falseはOFF, trueはON）

// 土壌水分センサーの定義
const float moistureInAir = 535;   // 空中でのセンサーの値
const float moistureInWater = 280; // 水中でのセンサーの値
const int sensorPin = A0;          // センサーピン
int sensorValue = 0;               // センサーからの生データ
float moisturePercentage = 0;      // 土壌水分のパーセンテージ計算値

int waterThreshold = 30;  // 水やりを開始する土壌水分の閾値（パーセンテージ）

void setup() {
  Serial.begin(9600);         // シリアル通信の開始（ボーレート9600）
  pinMode(pump1A, OUTPUT);    // pump1Aを出力として設定
}

void loop() {
  sensorValue = analogRead(sensorPin);  // 土壌水分センサーから値を読み取る
  moisturePercentage = calculateMoisturePercentage(sensorValue);  // 水分パーセンテージを計算

  Serial.print("Soil Moisture Percentage: ");
  Serial.println(moisturePercentage);

  if (moisturePercentage > waterThreshold) {
    if (!pumpStatus) {
      turnOnPump();  // ポンプをONにする
    }
  } else {
    if (pumpStatus) {
      turnOffPump();  // ポンプをOFFにする
    }
  }
}

float calculateMoisturePercentage(int sensorValue) {
  // 土壌水分パーセンテージを計算
  return 100.0 * (1 - (float)(sensorValue - moistureInWater) / (moistureInAir - moistureInWater));
}

void turnOnPump() {
  digitalWrite(pump1A, HIGH);  // ポンプ1AにHIGH信号を送る
  pumpStatus = true;           // ポンプの状態をONに設定
  Serial.println("Pump turned ON");
}

void turnOffPump() {
  digitalWrite(pump1A, LOW);   // ポンプ1AにLOW信号を送る
  pumpStatus = false;          // ポンプの状態をOFFに設定
  Serial.println("Pump turned OFF");
}
