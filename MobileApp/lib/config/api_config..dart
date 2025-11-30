enum ApiBase {
  local('192.168.1.200:5000');

  final String url;
  const ApiBase(this.url);
}

enum ApiEndpoint {
  mobile('/mobile'),
  mobileAlarm('/mobile/alarm'),
  mobileSync('/mobile/sync');

  final String path;
  const ApiEndpoint(this.path);
}

