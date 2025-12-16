import 'package:flutter/material.dart';
import '../services/api_Service.dart';
import 'NavigationBar.dart';

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  final TextEditingController _usernameController = TextEditingController();
  final TextEditingController _keyController = TextEditingController();
  final FocusNode _keyFocusNode = FocusNode();
  bool _isLoading = false;
  String? _errorMessage;

  @override
  void dispose() {
    _usernameController.dispose();
    _keyController.dispose();
    _keyFocusNode.dispose();
    super.dispose();
  }

  Future<void> _handleLogin() async {
    final username = _usernameController.text.trim();
    final key = _keyController.text.trim();

    if (username.isEmpty || key.isEmpty) {
      setState(() {
        _errorMessage = "Please fill in all fields";
      });
      return;
    }

    setState(() {
      _isLoading = true;
      _errorMessage = null;
    });

    try {
      final response = await ApiService.instance.validateKey(key).timeout(
        const Duration(seconds: 2),
      );
      if (response['status'] == 'allow') {
        if (!mounted) return;
        Navigator.pushReplacement(
          context,
          MaterialPageRoute(
            builder: (context) => AppNavigationBar(username: username),
          ),
        );
      } else {
        setState(() {
          _errorMessage = "Wrong Key";
        });
      }
    } catch (e) {
      setState(() {
        _errorMessage = "Connection Timeout";
      });
    } finally {
      if (mounted) {
        setState(() {
          _isLoading = false;
        });
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    final screenHeight = MediaQuery.of(context).size.height;
    final screenWidth = MediaQuery.of(context).size.width;

     
    const backgroundColor = Color(0xFFDBE2EF);
    const accentColor = Colors.black;

    return Scaffold(
      backgroundColor: backgroundColor,
      body: SafeArea(
        child: SingleChildScrollView(
          padding: EdgeInsets.symmetric(horizontal: screenWidth * 0.08),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.center,
            children: [
              SizedBox(height: screenHeight * 0.1),

               
              Container(
                width: screenWidth * 0.25,
                height: screenWidth * 0.25,
                decoration: const BoxDecoration(
                  color: accentColor,  
                  shape: BoxShape.circle,
                ),
                child: Icon(
                  Icons.home_rounded,
                  color: Colors.white,
                  size: screenWidth * 0.12,
                ),
              ),
              SizedBox(height: screenHeight * 0.03),

               
              Text(
                'WELCOME HOME',
                style: TextStyle(
                  fontSize: screenWidth * 0.07,
                  fontWeight: FontWeight.w600,
                  color: Colors.black87,
                  letterSpacing: 0.5,
                ),
              ),
              SizedBox(height: screenHeight * 0.05),

               
              _buildTextField(
                controller: _usernameController,
                hintText: "Username",
                icon: Icons.person_outline,
                screenWidth: screenWidth,
                textInputAction: TextInputAction.next,
                onSubmitted: (_) {
                  FocusScope.of(context).requestFocus(_keyFocusNode);
                },
              ),
              SizedBox(height: screenHeight * 0.02),

               
              _buildTextField(
                controller: _keyController,
                hintText: "Access Key",
                icon: Icons.vpn_key_outlined,
                isObscure: true,
                screenWidth: screenWidth,
                focusNode: _keyFocusNode,
                textInputAction: TextInputAction.done,
                onSubmitted: (_) => _handleLogin(),
              ),

              SizedBox(height: screenHeight * 0.05),

               
              SizedBox(
                width: double.infinity,
                height: screenHeight * 0.07,
                child: ElevatedButton(
                  onPressed: _isLoading ? null : _handleLogin,
                  style: ElevatedButton.styleFrom(
                    backgroundColor: accentColor,
                    foregroundColor: Colors.white,
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(screenWidth * 0.04),
                    ),
                    elevation: 5,
                  ),
                  child: Text(
                    "ENTER",
                    style: TextStyle(
                      fontSize: screenWidth * 0.05,
                      fontWeight: FontWeight.bold,
                      letterSpacing: 1.0,
                    ),
                  ),
                ),
              ),

              if (_errorMessage != null) ...[
                SizedBox(height: screenHeight * 0.02),
                Text(
                  _errorMessage!,
                  style: const TextStyle(
                    color: Colors.red,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ],
            ],
          ),
        ),
      ),
    );
  }

  Widget _buildTextField({
    required TextEditingController controller,
    required String hintText,
    required IconData icon,
    required double screenWidth,
    bool isObscure = false,
    TextInputAction? textInputAction,
    Function(String)? onSubmitted,
    FocusNode? focusNode,
  }) {
    return Container(
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(screenWidth * 0.04),
        boxShadow: [
          BoxShadow(
            color: Colors.black.withOpacity(0.05),
            blurRadius: 10,
            offset: const Offset(0, 5),
          ),
        ],
      ),
      child: TextField(
        controller: controller,
        obscureText: isObscure,
        focusNode: focusNode,
        textInputAction: textInputAction,
        onSubmitted: onSubmitted,
        style: const TextStyle(color: Colors.black87),
        decoration: InputDecoration(
          hintText: hintText,
          hintStyle: TextStyle(color: Colors.grey.shade400),
          prefixIcon: Icon(icon, color: Colors.black54),
          border: InputBorder.none,
          contentPadding: const EdgeInsets.symmetric(
            horizontal: 20,
            vertical: 16,
          ),
        ),
      ),
    );
  }
}

