class doorsData{
  static final doorsData _instance = doorsData._internal();
  factory doorsData() => _instance;
  doorsData._internal();

  int homeDoor = 0;
  int garageDoor = 0;
}
