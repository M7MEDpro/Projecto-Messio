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
    print("Setting brightnessRoom1 to $value");
    _api.put("brightnessRoom1", value.toString());
  }

  @override
  void setMode(int value) {
    _data.mode = value;
    print("Setting modeRoom1 to $value");
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
    print("Setting ldrRoom1 to $apiValue");
    _api.put("ldrRoom1", apiValue.toString());
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
    print("Setting irRoom1 to $apiValue");
    _api.put("irRoom1", apiValue.toString());
    print("Mode after motion update: ${_data.mode}");
  }
}
