import 'package:smart_homr/data/doors_Data.dart';

import '../services/api_Service.dart';

class doorsManager{
  static final doorsManager _instance = doorsManager._internal();
  factory doorsManager() => _instance;
  doorsManager._internal();

  doorsData data = doorsData();

  Future<void> syncDoors() async {
    try {
      final response = await ApiService.instance.get("sync/doors");
      if (response != null) {
        if (response['mainDoor'] != null) data.homeDoor = response['mainDoor'];
        if (response['garageDoor'] != null) data.garageDoor = response['garageDoor'];
      }
    } catch (e) {
      print('Error syncing doors: $e');
    }
  }

  void openMain(int s){
    data.homeDoor = 1;
    ApiService.instance.put("mainDoor", data.homeDoor);
  }
  void closeMain(int s){
    data.homeDoor = 0;
    ApiService.instance.put("mainDoor", data.homeDoor);
  }
  void openGarage(int s){
    data.garageDoor = 1;
    ApiService.instance.put("garageDoor", data.garageDoor);
  }
  void closeGarage(int s){
    data.garageDoor = 0;
    ApiService.instance.put("garageDoor", data.garageDoor);
  }

}