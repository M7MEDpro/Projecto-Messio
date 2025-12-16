import 'package:smart_homr/services/api_Service.dart';
import '../../data/rooms/office_room.dart';
import '../../data/rooms/bedroom_room.dart';
import '../../data/rooms/living_room.dart';
import '../../data/rooms/garage_room.dart';
import '../../data/rooms/yard_room.dart';

class SyncRooms {
  ApiService api = ApiService.instance;

  Future<void> syncRooms() async {
    try {
      final response = await api.get("sync/rooms");

       
      if (response['brightnessRoom2'] != null) OfficeRoomData().brightness = response['brightnessRoom2'];
      if (response['modeRoom2'] != null) OfficeRoomData().mode = response['modeRoom2'];
      if (response['ldrRoom2'] != null) OfficeRoomData().daylight = response['ldrRoom2'] == 1;
      if (response['irRoom2'] != null) OfficeRoomData().motion = response['irRoom2'] == 1;

       
      if (response['brightnessRoom1'] != null) BedroomRoomData().brightness = response['brightnessRoom1'];
      if (response['modeRoom1'] != null) BedroomRoomData().mode = response['modeRoom1'];
      if (response['ldrRoom1'] != null) BedroomRoomData().daylight = response['ldrRoom1'] == 1;
      if (response['irRoom1'] != null) BedroomRoomData().motion = response['irRoom1'] == 1;

       
      if (response['brightnessReception'] != null) LivingRoomData().brightness = response['brightnessReception'];
      if (response['modeReception'] != null) LivingRoomData().mode = response['modeReception'];
      if (response['ldrReception'] != null) LivingRoomData().daylight = response['ldrReception'] == 1;
      if (response['irReception'] != null) LivingRoomData().motion = response['irReception'] == 1;

       
      if (response['brightnessGarage'] != null) GarageRoomData().brightness = response['brightnessGarage'];
      if (response['modeGarage'] != null) GarageRoomData().mode = response['modeGarage'];
      if (response['ldrGarage'] != null) GarageRoomData().daylight = response['ldrGarage'] == 1;
      if (response['irGarage'] != null) GarageRoomData().motion = response['irGarage'] == 1;

       
      if (response['brightnessOuterLed'] != null) YardRoomData().brightness = response['brightnessOuterLed'];
      if (response['modeOuterLed'] != null) YardRoomData().mode = response['modeOuterLed'];
      if (response['ldrOuterLed'] != null) YardRoomData().daylight = response['ldrOuterLed'] == 1;

    } catch (e) {
      print('Error syncing rooms: $e');
    }
  }
}

