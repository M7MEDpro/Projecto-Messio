import 'package:flutter/material.dart';


class login  extends StatefulWidget {
  const login ({super.key});

  @override
  State<login> createState() => _loginState();
}

class _loginState extends State<login> {
  Widget build(BuildContext context) {
    double screenHeight = MediaQuery.of(context).size.height;
    double screenWidth = MediaQuery.of(context).size.width;

    return Scaffold (
      body: Container(
        padding: EdgeInsets.symmetric(horizontal: screenWidth * 0.05),
        width: screenWidth,
        child: SingleChildScrollView(
          child: Column (
              children:<Widget> [
                 SizedBox (height : screenHeight * 0.18),
                TextField(
                  decoration: InputDecoration(
                    hintText: 'Email',
                    prefixIcon: const Icon(Icons.email),


                    enabledBorder: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(screenWidth * 0.05),
                      borderSide: const BorderSide(
                        color: Colors.red,
                        width: 1.0,
                      ),
                    ),

                    disabledBorder: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(screenWidth * 0.05),
                      borderSide: const BorderSide(
                        color: Colors.red,
                        width: 1.0,
                      ),
                    ),

                    focusedBorder: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(screenWidth * 0.05),
                      borderSide: const BorderSide(
                        color: Colors.red,
                        width: 1.0,
                      ),
                    ),
                  ),
                ),
                 SizedBox (height : screenHeight * 0.035),

                TextField(
                  decoration: InputDecoration(
                    hintText: 'password',

                    enabledBorder: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(screenWidth * 0.05),
                      borderSide: const BorderSide(
                        color: Colors.red,
                        width: 1.0,
                      ),
                    ),

                    disabledBorder: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(screenWidth * 0.05),
                      borderSide: const BorderSide(
                        color: Colors.blueAccent,
                        width: 1.0,
                      ),
                    ),

                    focusedBorder: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(screenWidth * 0.05),
                      borderSide: const BorderSide(
                        color: Colors.red,
                        width: 1.0,
                      ),
                    ),
                  ),
                ),
                SizedBox(height: screenHeight * 0.025),
                MaterialButton(
                  elevation: 5.0,
                  color: Colors.blue,
                  padding: EdgeInsets.symmetric(
                      vertical: screenHeight * 0.025, horizontal: screenWidth * 0.2), // EdgeInsets
                  child:  Text(
                    'Login',
                    style: TextStyle(
                      color: Colors.white,
                      fontSize: screenWidth * 0.06,
                      fontWeight: FontWeight.bold,
                    ), // TextStyle
                  ), // Text
                  shape: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(screenWidth * 0.12),
                    borderSide: BorderSide.none,
                  ), // OutlineInputBorder
                  onPressed: () {}, // MaterialButton
                )


              ]
          ),
        ),


      ),
    );
  }
}
