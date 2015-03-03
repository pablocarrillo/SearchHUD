//
//  SearchHUD.h
//  SearchHUD-Demo
//
//  Created by Pradyumna Doddala on 31/12/12.
//  Copyright (c) 2012 Pradyumna Doddala. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PDSearchHUD;

typedef enum {
    PDSearchTypeBeginsWith,
    PDSearchTypeContains
} PDSearchType;

//Use a 20 point insets for each side plus 20 on the top for the statusbar
#define PDSEARCHHUD_DEFAULT_INSETS UIEdgeInsetsMake(20,20,20,20)

@protocol PDSearchHUDDelegate <NSObject>

/**
* @brief Called after User taps on the List and index of the item is returned
* @param index the index of the cell taped
*/
- (void)searchHUD:(PDSearchHUD *)searchHUD didSelectRowAtIndex:(NSUInteger)index;

/**
* @brief Called after User taps on the List and value is returned
* @param item the string of the cell tapped
*/

- (void)searchHUD:(PDSearchHUD *)searchHUD didSelectItem:(NSString *)item;
@end

@interface PDSearchHUD : UIView <UITableViewDataSource, UITableViewDelegate, UISearchBarDelegate>

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (weak, nonatomic) IBOutlet UISearchBar *searchBar;
@property (weak, nonatomic) IBOutlet UIView *backgroundView;

@property (nonatomic, weak) id <PDSearchHUDDelegate>delegate;
@property (nonatomic, strong) NSArray *searchList;

// Value that determines whether the HUD to dismiss after row selection
@property (nonatomic) BOOL dismissWhenRowSelected;

//Used to determine the Comparison type
@property (nonatomic) PDSearchType searchType;

/**
* @brief designated initializer
*
* @param list and array of NSStrings to be use on the table
* @param aDelegate the PDSearchHUDDelegate to be use
*
* @return and instance of PDSearchHUD
*
*/
- (instancetype)initWithSearchList:(NSArray *)list andDelegate:(id)aDelegate;

/**
* @brief call this method instead of addSubview in the superview to add the PDSearchHUD with the proper constraints to the superView
* @param superview the view to hold the PDSearchHUD
*/
- (void)addToSuperView:(UIView *)superview withInsets:(UIEdgeInsets)insets;
@end
