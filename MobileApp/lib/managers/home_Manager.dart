import 'package:smart_homr/services/api_Service.dart';
import '../data/home_Modes_Data.dart';

import '../data/rooms/office_room.dart';
import '../data/rooms/bedroom_room.dart';
import '../data/rooms/living_room.dart';
import '../data/rooms/garage_room.dart';
import '../data/rooms/yard_room.dart';

import 'rooms/office_room.dart';
import 'rooms/bedroom_room_manager.dart';
import 'rooms/living_room_manager.dart';
import 'rooms/garage_room_manager.dart';
import 'rooms/yard_room_manager.dart';
import 'rooms/sync_rooms.dart';

class HomeManager{
  static final HomeManager _instance = HomeManager._internal();
  factory HomeManager() => _instance;
  HomeManager._internal();

  ApiService api = ApiService.instance;
  HomeModesData homeModes = HomeModesData();

  // Initialize all room data
  OfficeRoomData officeData = OfficeRoomData();
  BedroomRoomData bedroomData = BedroomRoomData();
  LivingRoomData livingData = LivingRoomData();
  GarageRoomData garageData = GarageRoomData();
  YardRoomData yardData = YardRoomData();

  // Initialize all room managers
  late OfficeRoomManager officeManager = OfficeRoomManager(officeData);
  late BedroomRoomManager bedroomManager = BedroomRoomManager(bedroomData);
  late LivingRoomManager livingManager = LivingRoomManager(livingData);
  late GarageRoomManager garageManager = GarageRoomManager(garageData);
  late YardRoomManager yardManager = YardRoomManager(yardData);

  final Map<String, int> _savedBrightness = {};

  HomeModesData getHomeModes(){
    return homeModes;
  }
  
  setHomeAway(bool value){
    homeModes.homeAway = value;
    String apiValue = (value ? 1 : 0).toString();
    api.put("homeAway", apiValue);
  }
  
  setBedTime(bool value){
    homeModes.bedTime = value;
    String apiValue = (value ? 1 : 0).toString();
    api.put("bedTimeMode", apiValue);
  }
  
  Future<void> setPowerSaving(bool value) async {
    homeModes.powerSaving = value;
    String apiValue = (value ? 1 : 0).toString();
    api.put("powerSavingMode", apiValue);

    if (value) {
      _savedBrightness['office'] = officeData.brightness;
      officeManager.setBrightness(30);
      await Future.delayed(const Duration(milliseconds: 20));

      _savedBrightness['bedroom'] = bedroomData.brightness;
      bedroomManager.setBrightness(30);
      await Future.delayed(const Duration(milliseconds: 20));

      _savedBrightness['living'] = livingData.brightness;
      livingManager.setBrightness(30);
      await Future.delayed(const Duration(milliseconds: 20));

      _savedBrightness['garage'] = garageData.brightness;
      garageManager.setBrightness(30);
      await Future.delayed(const Duration(milliseconds: 20));

      _savedBrightness['yard'] = yardData.brightness;
      yardManager.setBrightness(30);

    } else {
      // Restore brightness
      if (_savedBrightness.containsKey('office')) {
        officeManager.setBrightness(_savedBrightness['office']!);
        await Future.delayed(const Duration(milliseconds: 20));
      }
      if (_savedBrightness.containsKey('bedroom')) {
        bedroomManager.setBrightness(_savedBrightness['bedroom']!);
        await Future.delayed(const Duration(milliseconds: 20));
      }
      if (_savedBrightness.containsKey('living')) {
        livingManager.setBrightness(_savedBrightness['living']!);
        await Future.delayed(const Duration(milliseconds: 20));
      }
      if (_savedBrightness.containsKey('garage')) {
        garageManager.setBrightness(_savedBrightness['garage']!);
        await Future.delayed(const Duration(milliseconds: 20));
      }
      if (_savedBrightness.containsKey('yard')) {
        yardManager.setBrightness(_savedBrightness['yard']!);
      }

      _savedBrightness.clear();
    }
  }
  
  setEmergency(bool value){
    homeModes.emergency = value;
    String apiValue = (value ? 1 : 0).toString();
    api.put("EmergencyMode", apiValue);
  }

  Future<void> syncHomeModes() async {
    try {
      final response = await api.get("sync/home-modes");
      if (response != null) {
        homeModes.homeAway = response['homeAway'] == 1;
        homeModes.bedTime = response['bedTimeMode'] == 1;
        homeModes.powerSaving = response['powerSavingMode'] == 1;
        homeModes.emergency = response['EmergencyMode'] == 1;
        homeModes.powerConsumption = (response['powerConsumption'] as num).toDouble();
      }
    } catch (e) {
      print('Error syncing home modes: $e');
    }
  }

  Future<void> syncRooms() async {
    await SyncRooms().syncRooms();
  }
}
