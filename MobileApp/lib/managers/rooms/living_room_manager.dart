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
    print("Setting brightnessReception to $value");
    _api.put("brightnessReception", value.toString());
  }

  @override
  void setMode(int value) {
    _data.mode = value;
    print("Setting modeReception to $value");
    _api.put("modeReception", value.toString());
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
    print("Setting ldrReception to $apiValue");
    _api.put("ldrReception", apiValue.toString());
    print("Mode after daylight update: ${_data.mode}");
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
    print("Setting irReception to $apiValue");
    _api.put("irReception", apiValue.toString());
    print("Mode after motion update: ${_data.mode}");
  }
}