//
//  IAPHelper.h
//  BookCat
//
//  Created by vector on 14-4-18.
//
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import <StoreKit/SKPaymentTransaction.h>


@class IAPHelper;
@protocol IAPHelperDelegate <NSObject>

//购买
-(void)requestProduct:(IAPHelper*)sender start:(SKProductsRequest*)request;
-(void)requestProduct:(IAPHelper*)sender received:(SKProductsRequest*)request;

-(void)paymentRequest:(IAPHelper*)sender start:(SKPayment*)payment;
-(void)paymentRequest:(IAPHelper*)sender purchased:(SKPaymentTransaction*)transaction;
-(void)paymentRequest:(IAPHelper*)sender restored:(SKPaymentTransaction*)transaction;
-(void)paymentRequest:(IAPHelper*)sender failed:(SKPaymentTransaction*)transaction;
//不支持内购
-(void)iapNotSupported:(IAPHelper*)sender;
//结束
-(void)paymentRequestFinish:(IAPHelper*)sender;
@end

@interface IAPHelper : NSObject

+(IAPHelper*)getInstance;

@property(nonatomic,assign) id<IAPHelperDelegate> delegate;

-(void)setup;
-(void)destroy;
-(void)buy:(NSString*)productId;

-(void)restore;
@end
