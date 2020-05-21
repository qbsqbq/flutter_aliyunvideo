#include "AppDelegate.h"
#include "GeneratedPluginRegistrant.h"
#import "AliyunVideoPlugin.h"
@implementation AppDelegate

- (BOOL)application:(UIApplication *)application

    didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  
    [GeneratedPluginRegistrant registerWithRegistry:self];
      
    [AliyunVideoPlugin registerWithRegistrar: [self registrarForPlugin:@"aliyun_video"]];
        
    
  return [super application:application didFinishLaunchingWithOptions:launchOptions];
    
}



@end
