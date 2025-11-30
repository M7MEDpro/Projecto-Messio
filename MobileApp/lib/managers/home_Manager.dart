import 'package:smart_homr/services/api_Service.dart';

import '../data/home_Modes_Data.dart';

class HomeManager{
  ApiService api = ApiService.instance;
  HomeModesData homeModes = HomeModesData();

  HomeModesData getHomeModes(){
    return homeModes;
  }
  setHomeAway(bool value){
    String apiValue = (value ? 1 : 0).toString();
    api.put("homeAway", apiValue);
  }
  setBedTime(bool value){
    String apiValue = (value ? 1 : 0).toString();
    api.put("bedTimeMode", apiValue);
  }
  setPowerSaving(bool value){
    String apiValue = (value ? 1 : 0).toString();
    api.put("powerSavingMode", apiValue);
  //to do later
  }
  setEmergency(bool value){
    String apiValue = (value ? 1 : 0).toString();
    api.put("EmergencyMode", apiValue);

  }






}
