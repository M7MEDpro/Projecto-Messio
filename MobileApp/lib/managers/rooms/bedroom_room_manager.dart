import 'package:smart_homr/managers/rooms/room.dart';
import '../../data/rooms/bedroom_room.dart';
import '../../services/api_Service.dart';

class BedroomRoomManager implements RoomManager {
  final BedroomRoomData _data;
  final ApiService _api = ApiService.instance;

  BedroomRoomManager(this._data);

  @override
  void setBrightness(int value) {
    _data.brightness = value;
    _api.put("brightnessRoom1", value.toString());
  }

  @override
  void setMode(int value) {
    _data.mode = value;
    _api.put("modeRoom1", value.toString());
  }

  @override
  void setDaylight(bool value) {
    _data.daylight = value;

    if (value || _data.motion) {
      _data.mode = 2; // Auto mode
    } else {
      _data.mode = (_data.mode == 1) ? 1 : 0;
    }

    int apiValue = value ? 1 : 0;
    _api.put("ldrRoom1", apiValue.toString());
    _api.put("modeRoom1", _data.mode.toString());
  }

  @override
  void setMotion(bool value) {
    _data.motion = value;

    if (value || _data.daylight) {
      _data.mode = 2; // Auto mode
    } else {
      _data.mode = (_data.mode == 1) ? 1 : 0;
    }

    int apiValue = value ? 1 : 0;
    _api.put("irRoom1", apiValue.toString());
    _api.put("modeRoom1", _data.mode.toString());
  }
}