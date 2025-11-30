import 'package:smart_homr/managers/rooms/room.dart';

import '../../data/rooms/yard_room.dart';
import '../../services/api_Service.dart';

class YardRoomManager implements RoomManager {
  final YardRoomData _data;
  final ApiService _api = ApiService.instance;

  YardRoomManager(this._data);

  @override
  void setBrightness(int value) {
    _data.brightness = value;
    print("Setting brightnessOuterLed to $value");
    _api.put("brightnessOuterLed", value.toString());
  }

  @override
  void setMode(int value) {
    _data.mode = value;
    print("Setting modeOuterLed to $value");
    _api.put("modeOuterLed", value.toString());
  }

  @override
  void setDaylight(bool value) {
    _data.daylight = value;
    if (value) {
      _data.mode = 2; // Auto mode
    } else {
      _data.mode = (_data.mode == 1) ? 1 : 0;
    }

    int apiValue = value ? 1 : 0;
    print("Setting ldrOuterLed to $apiValue");
    _api.put("ldrOuterLed", apiValue.toString());
    print("Mode after daylight update: ${_data.mode}");
  }

  @override
  void setMotion(bool value) {
  }
}