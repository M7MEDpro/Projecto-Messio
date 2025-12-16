import 'package:smart_homr/data/rooms/room.dart';
import '../../services/api_Service.dart';

class YardRoomData implements RoomData {
  static final YardRoomData _instance = YardRoomData._internal();
  factory YardRoomData() => _instance;
  YardRoomData._internal();

  ApiService api = ApiService.instance;

  @override
  int brightness = 0;

  @override
  bool daylight = false;

  @override
  bool motion = false;

  @override
  int mode = 0;
}
