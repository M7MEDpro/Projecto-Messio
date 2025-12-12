import 'package:smart_homr/data/rooms/room.dart';
import '../../services/api_Service.dart';

class GarageRoomData implements RoomData {
  static final GarageRoomData _instance = GarageRoomData._internal();
  factory GarageRoomData() => _instance;
  GarageRoomData._internal();

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