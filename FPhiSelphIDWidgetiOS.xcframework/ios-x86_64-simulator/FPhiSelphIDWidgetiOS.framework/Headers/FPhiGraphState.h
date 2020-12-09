
#import <UIKit/UIKit.h>

#include "FPBSelphIDDocumentRawData.h"

#include "FPhiAbbyyEngine.h"
#import "FPhiSelphIDDocumentManager.h"

@class FPhiGraph;

@interface FPhiGraphState : NSObject

@property FPhiGraph *graph;

// Variables para la lectura de todas las fases de ML
@property dispatch_semaphore_t lockML;
@property int MLSuccessCaptures;

@property (atomic) bool processing_new_state;
@property (atomic) bool processing_execute;
@property (atomic) bool processing_image;
@property (atomic) bool tokenizing_finished;

@property (nonatomic) CGPoint lastDetectionUpperLeft;
@property (nonatomic) CGPoint lastDetectionUpperRight;
@property (nonatomic) CGPoint lastDetectionLowerLeft;
@property (nonatomic) CGPoint lastDetectionLowerRight;


-(void)onEnterState:(NSString *)stateName :(NSString *)stateNamePrev :(CGSize)canvasSize;
-(void)calculateButtonPosition:(NSString *)stateName :(CGSize)canvasSize;
-(void)execute:(NSString *)stateName :(CGSize)canvasSize;
-(void)onTap:(NSString *)stateName :(CGPoint)position :(CGSize)canvasSize;
-(void)onTouchesBegan:(NSString *)stateName :(NSSet<UITouch *> *)touches :(UIView *)view;
-(void)onTouchesEnded:(NSString *)stateName :(NSSet<UITouch *> *)touches :(UIView *)view;
-(void)onSwipe:(NSString *)stateName :(UISwipeGestureRecognizer *)swipe;
-(void)onPlayerDidReachEnd:(NSString *)stateName :(NSNotification *)notification;

-(void)draw:(CGContextRef)context :(CGSize)canvasSize :(NSString *)stateName :(NSString *)stateNamePrev :(float)deltaTime;

/// ABBYY Engine
-(id<AbbyyCameraCallback>)getCameraInputCallback;
-(void)setROI:(CGRect)roi;
-(void)setDocumentManager:(FPhiSelphIDDocumentManager *)manager;

@end
