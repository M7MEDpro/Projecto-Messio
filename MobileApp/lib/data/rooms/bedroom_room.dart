import 'package:smart_homr/data/rooms/room.dart';
import '../../services/api_Service.dart';

class BedroomRoomData implements RoomData {
  static final BedroomRoomData _instance = BedroomRoomData._internal();
  factory BedroomRoomData() => _instance;
  BedroomRoomData._internal();

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