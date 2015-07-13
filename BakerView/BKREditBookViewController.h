//
//  RootViewController.h
//  Baker
//
//  ==========================================================================================
//
//  Copyright (c) 2010-2013, Davide Casali, Marco Colombo, Alessandro Morandi
//  Copyright (c) 2014, Andrew Krowczyk, Cédric Mériau, Pieter Claerhout
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification, are
//  permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this list of
//  conditions and the following disclaimer.
//  Redistributions in binary form must reproduce the above copyright notice, this list of
//  conditions and the following disclaimer in the documentation and/or other materials
//  provided with the distribution.
//  Neither the name of the Baker Framework nor the names of its contributors may be used to
//  endorse or promote products derived from this software without specific prior written
//  permission.
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//


#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "BKRIndexViewController.h"
#import "BKRModalWebViewController.h"
#import "BKRBook.h"
#import "BKRBookStatus.h"

#import "DetailsTableViewCell.h"

@class Downloader;

@interface BKREditBookViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {

    CGRect screenBounds;

    NSArray *supportedOrientation;

    NSString *defaultScreeshotsPath;
    NSString *cachedScreenshotsPath;

    NSString *renderingType;

    NSMutableArray *pages;
    NSMutableArray *toLoad;

    NSMutableArray *pageDetails;
    NSMutableDictionary *attachedScreenshotPortrait;
    NSMutableDictionary *attachedScreenshotLandscape;

    UIImage *backgroundImageLandscape;
    UIImage *backgroundImagePortrait;

    NSString *pageNameFromURL;
    NSString *anchorFromURL;

    int tapNumber;
    int stackedScrollingAnimations;

    BOOL currentPageFirstLoading;
    BOOL currentPageIsDelayingLoading;
    BOOL currentPageHasChanged;
    BOOL currentPageIsLocked;
    BOOL currentPageWillAppearUnderModal;

    BOOL userIsScrolling;
    BOOL shouldPropagateInterceptedTouch;
    BOOL shouldForceOrientationUpdate;

    BOOL adjustViewsOnAppDidBecomeActive;

    //UIScrollView *scrollView;
    //UIWebView *prevPage;
    //UIWebView *currPage;
    //UIWebView *nextPage;

    //UIColor *webViewBackground;

    //CGRect upTapArea;
    //CGRect downTapArea;
    //CGRect leftTapArea;
    //CGRect rightTapArea;

    //int totalPages;
    //int lastPageNumber;
    //int currentPageNumber;

    int pageWidth;
    int pageHeight;
    int currentPageHeight;

    //NSString *URLDownload;
    //Downloader *downloader;
    //UIAlertView *feedbackAlert;

    //BKRIndexViewController *indexViewController;
    //BKRModalWebViewController *myModalViewController;
    //BookDetailsViewController *detailsViewController;
    
    BKRBookStatus *bookStatus;
}

#pragma mark - Properties

@property (nonatomic, strong) BKRBook *book;
//@property (nonatomic, strong) UIScrollView *scrollView;
//@property (nonatomic, strong) UIWebView *currPage;

//@property (nonatomic, assign) int currentPageNumber;
@property (strong,nonatomic)  UITableView *indexTableView;
@property (strong,nonatomic) UIView *detailsView;
@property (nonatomic, assign) BOOL barsHidden;

#pragma mark - Initialization

- (id)initWithBook:(BKRBook*)bakerBook;
- (BOOL)loadBookWithBookPath:(NSString*)bookPath;
- (void)cleanupBookEnvironment;
- (void)resetPageSlots;
- (void)resetPageDetails;
- (void)buildPageArray;
- (void)startReading;
- (void)buildPageDetails;
- (void)setImageFor:(UIImageView*)view;
- (void)updateBookLayout;
- (void)adjustScrollViewPosition;
- (void)setPageSize:(NSString*)orientation;
- (void)setTappableAreaSizeForOrientation:(NSString*)orientation;
- (void)showPageDetails;
- (void)setFrame:(CGRect)frame forPage:(UIWebView*)page;
- (void)setupWebView:(UIWebView*)webView;
- (void)removeWebViewDoubleTapGestureRecognizer:(UIView*)view;


#pragma mark - Navigation Bars

- (CGRect)getNewNavigationFrame:(BOOL)hidden;
- (void)toggleBars;
- (void)showBars;
- (void)showNavigationBar;
- (void)hideBars:(NSNumber*)animated;
- (void)handleBookProtocol:(NSURL*)url;

#pragma mark - Orientation

- (NSString*)getCurrentInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

#pragma mark - Index View

- (BOOL)isIndexView:(UIWebView*)webView;

@end
