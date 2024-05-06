# Simple Moisture Control System

## 概要
このリポジトリは、Arduinoを使用した土壌水分センサーに基づく自動水やりシステムの最小構成を制御するためのプログラムが含まれています。このプロジェクトは、特に屋内植物や小規模な農園での使用に適しており、「SunFounder Ultimate Sensor Kit」を使用しています。

## 主な機能
- 土壌の水分量に基づいて自動的に水やりを行います。
- 水やりの閾値はプログラム内で調整可能です。
- Arduino Unoと容量性土壌水分センサーを使用します。

## 必要条件
- Arduino IDE
- Arduino Uno R4ボード
- [SunFounder Ultimate Sensor Kit](https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/)
- 適切な配線材料

## セットアップ
以下の手順に従って、ハードウェアを組み立ててソフトウェアをインストールしてください:
1. Arduino Unoに「SunFounder Ultimate Sensor Kit」からのセンサーと水ポンプを接続します。回路構成の詳細は[こちら](https://docs.sunfounder.com/projects/ultimate-sensor-kit/ja/latest/iot_project/07-iot_Auto_watering_system.html)を参照してください。
2. Arduino IDEを使用して、このリポジトリのスケッチをArduinoボードにアップロードします。

## 使用方法
1. スケッチをアップロードした後、Arduinoボードを電源に接続します。
2. 土壌水分センサーを植物の土に挿入します。
3. システムが自動的に土壌の水分をモニターし、必要に応じて水やりを行います。

## ライセンス
このプロジェクトは[MITライセンス](LICENSE)の下で公開されています。詳細は`LICENSE`ファイルを参照してください。

## 作者
Murasan201  
[https://murasan-net.com/](https://murasan-net.com/)

## 謝辞
このプロジェクトを可能にしたすべてのサポートとリソースを提供してくれた皆様に感謝します。
