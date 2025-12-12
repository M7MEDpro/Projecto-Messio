class Config {
  static const String ip = "192.168.1.104";
  static const int port = 5000;
  static const String apiKey = "home12345";
}

enum ApiBase {
  local;

  String get url => "${Config.ip}:${Config.port}";
  static String get key => Config.apiKey;
}

enum ApiEndpoint {
  mobile('/mobile'),
  mobileAlarm('/mobile/alarm'),
  mobileSync('/mobile/sync');

  final String path;
  const ApiEndpoint(this.path);
}
