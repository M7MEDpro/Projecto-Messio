import 'package:smart_homr/data/doors_Data.dart';

import '../services/api_Service.dart';

class doorsManager{
  doorsData data = doorsData();
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