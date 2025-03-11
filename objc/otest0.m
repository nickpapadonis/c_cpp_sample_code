#import <Foundation/Foundation.h>

@interface Fraction: NSObject

-(void) print;
-(void) setNumerator: (int) n;
-(void) setDenominator: (int) d;
-(int) getNumerator;
-(int) getDenominator;
@end

@implementation Fraction
int numerator;
int denominator;

-(void) print
{
  NSLog (@" %i/%i ", numerator, denominator);
}

-(void) setNumerator: (int) n
{
  numerator = n;
}

-(void) setDenominator: (int) d
{
  denominator = d;
}

-(int) getNumerator
{
  return numerator;
}

-(int) getDenominator
{
  return denominator;
}

-(void) setTo: (int) n over: (int) d
{
  numerator = n; denominator = d;
}

-(void) set: (int) n : (int) d;
{
  numerator = n; denominator = d;
}

- (void)dealloc
{
  NSLog(@"Object deallocated");
  [super dealloc];
}

@end

int main (int argc, char * argv[])
{
  @autoreleasepool {
    Fraction *aFraction = [[Fraction alloc] init];
    Fraction *bFraction = [[Fraction alloc] init];

    NSLog (@"retainCount %lu\n", [aFraction retainCount]);
    
    [aFraction setNumerator: 1];
    [aFraction setDenominator: 4];
    [aFraction print];

    [bFraction setNumerator: 99];
    [bFraction setDenominator: 100];
    [bFraction print];

    bFraction.numerator = 101;
    [bFraction print];

    [aFraction setTo: 100 over: 200];
    [aFraction print];

    [aFraction set :300 :400];
    [aFraction print];

    [aFraction release];
    [bFraction release];
      
    aFraction = bFraction = nil;
  }
  return 0;
}
