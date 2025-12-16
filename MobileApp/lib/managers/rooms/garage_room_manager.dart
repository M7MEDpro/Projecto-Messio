import 'package:smart_homr/managers/rooms/room.dart';
import '../../data/rooms/garage_room.dart';
import '../../services/api_Service.dart';

class GarageRoomManager implements RoomManager {
  final GarageRoomData _data;
  final ApiService _api = ApiService.instance;

  GarageRoomManager(this._data);

  @override
  void setBrightness(int value) {
    _data.brightness = value;
    _api.put("brightnessGarage", value.toString());
  }

  @override
  void setMode(int value) {
    _data.mode = value;
    _api.put("modeGarage", value.toString());
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
    _api.put("ldrGarage", apiValue.toString());
    _api.put("modeGarage", _data.mode.toString());
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
    _api.put("irGarage", apiValue.toString());
    _api.put("modeGarage", _data.mode.toString());
  }
}
