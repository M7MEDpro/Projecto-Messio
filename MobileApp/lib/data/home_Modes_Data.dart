class HomeModesData {
  static final HomeModesData _instance = HomeModesData._internal();
  factory HomeModesData() => _instance;
  HomeModesData._internal();

  bool homeAway = false;
  bool bedTime = false;
  bool powerSaving = false;
  bool emergency = false;
  double powerConsumption = 1.2;
}