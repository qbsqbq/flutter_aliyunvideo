

/*
*ExpansionTile(闭合列表)
* */
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
void main() => runApp(MyApp());
class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return new MaterialApp(
      title: "flutter demo",
      home: _home(),
    );
  }
}
class _home extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    return _homeState();
  }
}
class _homeState extends State<_home> {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return new Scaffold(
      appBar: new AppBar(
        title: new Text("首1页"),
      ),
      body: new Center(

              child: new RaisedButton(
                onPressed: (){
                  runiOSMethod();
                },
                color: Colors.red,
                padding: EdgeInsets.all(50.0),//按钮距离里面内容的内边距
                child: new Text('下一步'),
                textColor: Colors.white,//文字的颜色
                textTheme:ButtonTextTheme.normal ,//按钮的主题
              ),
            )
    );
  }
}

//调用原生方法
Future runiOSMethod() async {
  const platform = const MethodChannel('aliyun_video');
  var result;
  try {
    result = await platform.invokeMethod('startVideo');
    print(result);
    return Future.value(result);
  } on PlatformException catch (e) {
    return Future.error(e.toString());
  }
}