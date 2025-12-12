import 'package:smart_homr/data/rooms/room.dart';
import '../../services/api_Service.dart';

class LivingRoomData implements RoomData {
  static final LivingRoomData _instance = LivingRoomData._internal();
  factory LivingRoomData() => _instance;
  LivingRoomData._internal();

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