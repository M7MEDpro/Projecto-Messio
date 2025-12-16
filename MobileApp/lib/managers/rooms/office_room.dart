import 'package:smart_homr/managers/rooms/room.dart';
import '../../data/rooms/office_room.dart';
import '../../services/api_Service.dart';

class OfficeRoomManager implements RoomManager {
  final OfficeRoomData _data;
  final ApiService _api = ApiService.instance;

  OfficeRoomManager(this._data);

  @override
  void setBrightness(int value) {
    _data.brightness = value;
    _api.put("brightnessRoom2", value.toString());
  }

  @override
  void setMode(int value) {
    _data.mode = value;
    _api.put("modeRoom2", value.toString());
  }

  @override
  void setDaylight(bool value) {
    _data.daylight = value;

    if (value || _data.motion) {
      _data.mode = 2;  
    } else {
      _data.mode = (_data.mode == 1) ? 1 : 0;
    }

    int apiValue = value ? 1 : 0;
    _api.put("ldrRoom2", apiValue.toString());
    _api.put("modeRoom2", _data.mode.toString());
  }

  @override
  void setMotion(bool value) {
    _data.motion = value;

    if (value || _data.daylight) {
      _data.mode = 2;  
    } else {
      _data.mode = (_data.mode == 1) ? 1 : 0;
    }

    int apiValue = value ? 1 : 0;
    _api.put("irRoom2", apiValue.toString());
    _api.put("modeRoom2", _data.mode.toString());
  }
}

