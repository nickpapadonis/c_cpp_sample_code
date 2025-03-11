#import <Foundation/Foundation.h>

@interface A: NSObject
{ 
  @private
  int a;
}

@property int a;
@end

@implementation A
@synthesize a;
@end

int main (int argc, char * argv[])
{
  @autoreleasepool {
    A *a = [[A alloc] init];

    [a setA:99];
    int v = [a a];
    NSLog (@" %d\n", v);
  }
  return 0;
}
