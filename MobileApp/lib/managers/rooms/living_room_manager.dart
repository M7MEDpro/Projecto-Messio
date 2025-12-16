import 'package:smart_homr/managers/rooms/room.dart';
import '../../data/rooms/living_room.dart';
import '../../services/api_Service.dart';

class LivingRoomManager implements RoomManager {
  final LivingRoomData _data;
  final ApiService _api = ApiService.instance;

  LivingRoomManager(this._data);

  @override
  void setBrightness(int value) {
    _data.brightness = value;
    _api.put("brightnessReception", value.toString());
  }

  @override
  void setMode(int value) {
    _data.mode = value;
    _api.put("modeReception", value.toString());
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
    _api.put("ldrReception", apiValue.toString());
    _api.put("modeReception", _data.mode.toString());
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
    _api.put("irReception", apiValue.toString());
    _api.put("modeReception", _data.mode.toString());
  }
}
