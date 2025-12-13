import 'dart:convert';

import 'package:http/http.dart' as http;

import '../config/api_config..dart';

class ApiService{
  ApiService._privateConstructor();
  static final ApiService instance = ApiService._privateConstructor();

  void put(String key, dynamic value) async {
    try {
      final jsonBody = json.encode({key: value});

      print("PUT request JSON: $jsonBody");

      await http.put(
        Uri.http(ApiBase.local.url, ApiEndpoint.mobile.path),
        headers: {'Content-Type': 'application/json'},
        body: jsonBody,
      );
    } on Exception catch (e) {
      print(e);
    }
  }

  Future<Map<String, dynamic>> get(String endpoint) async {
    final uri = Uri.http(
        ApiBase.local.url,
        '${ApiEndpoint.mobile.path}/$endpoint'
    );

    final response = await http.get(uri);
    return json.decode(response.body);
  }

  Future<Map<String, dynamic>> validateKey(String key) async {
    final uri = Uri.http(ApiBase.local.url, '/auth/validate');
    final response = await http.post(
      uri,
      headers: {'Content-Type': 'application/json'},
      body: json.encode({'key': key}),
    );
    return json.decode(response.body);
  }
}