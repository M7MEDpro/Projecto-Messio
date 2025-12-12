import 'dart:convert';
import 'package:http/http.dart' as http;

class Weather {
  static double lastTemp = 0.0;

  static Future<double> getCurrentTemp() async {
    try {
      final data = await http.get(Uri.parse(
          'https://api.open-meteo.com/v1/forecast?latitude=30.0626&longitude=31.2497&current=temperature_2m'));
      final jsonData = jsonDecode(data.body);
      lastTemp = jsonData['current']['temperature_2m'];
      return lastTemp;
    } catch (e) {
      if (lastTemp != 0.0) return lastTemp;
      rethrow;
    }
  }
}