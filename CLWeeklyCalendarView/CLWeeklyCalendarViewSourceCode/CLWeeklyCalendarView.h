//
//  CLWeeklyCalendarView.h
//  Deputy
//
//  Created by Caesar on 30/10/2014.
//  Copyright (c) 2014 Caesar Li. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DailyCalendarView.h"

@protocol CLWeeklyCalendarViewDelegate <NSObject>

// Keys for customize the calendar behavior
extern NSString *const CLCalendarWeekStartDay;    //The Day of weekStart from 1 - 7 - Default: 1
extern NSString *const CLCalendarDayTitleTextColor; //Day Title text color,  Mon, Tue, etc label text color
extern NSString *const CLCalendarPastDayNumberTextColor;    //Day number text color for dates in the past
extern NSString *const CLCalendarFutureDayNumberTextColor;  //Day number text color for dates in the future
extern NSString *const CLCalendarCurrentDayNumberTextColor; //Day number text color for today
extern NSString *const CLCalendarSelectedDayNumberTextColor;    //Day number text color for the selected day
extern NSString *const CLCalendarSelectedCurrentDayNumberTextColor; //Day number text color when today is selected
extern NSString *const CLCalendarDotTextColor; //The color of the dot indicating an enabled date
extern NSString *const CLCalendarCurrentDayNumberBackgroundColor;   //Day number background color for today when not selected
extern NSString *const CLCalendarSelectedDayNumberBackgroundColor;  //Day number background color for selected day
extern NSString *const CLCalendarSelectedCurrentDayNumberBackgroundColor;   //Day number background color when today is selected
extern NSString *const CLCalendarSelectedDatePrintFormat;   //Selected Date print format,  - Default: @"EEE, d MMM yyyy"
extern NSString *const CLCalendarSelectedDatePrintColor;    //Selected Date print text color -Default: [UIColor whiteColor]
extern NSString *const CLCalendarSelectedDatePrintFontSize; //Selected Date print font size - Default : 13.f
extern NSString *const CLCalendarBackgroundImageColor;      //BackgroundImage color - Default : see applyCustomDefaults.
extern NSString *const CLCalendarDisabledDayTextColor;      //Day number text color for disabled dates
extern NSString *const CLCalendarDisabledDayBackgroundColor;      //Day number background color for disabled dates
extern NSString *const CLCalendarFont; //Preferred font of the calendar UI, default to system font. Font size passed here is ignored.

- (void)dailyCalendarViewDidSelect: (NSDate *)date;

@optional
- (NSDictionary *)CLCalendarBehaviorAttributes;       //Optional Function, Set the calendar behavior attributes by using above keys
/**
 *  Informs the weekly view which dates in a week span are enabled. These will be requested as you swipe through the weeks.
 *
 *  @param initialDate the first day of the given week
 *  @param finalDate   the last date of the given week
 
 *  @discussion The dictionary does not need to be exaustive, i.e., the simple absence of a date means it is disabled
 *
 *  @return the resulting dictionary, with dates as keys and boolean NSNumbers as values.
 */
- (NSDictionary<NSDate*, NSNumber*>*)enabledDatesFromDate:(NSDate*)initialDate toDate:(NSDate*)finalDate;

@end

@interface CLWeeklyCalendarView : UIView

@property (nonatomic, weak) id<CLWeeklyCalendarViewDelegate> delegate;
@property (nonatomic, strong) NSDate *selectedDate;
@property (nonatomic, strong) NSDictionary *calendarAttributes;

/**
 *  Array of dates you want to enable. Their behavior will depend on enabledDatesAppearance and disabledDatesInteractionEnabled
 */
@property (nonatomic, strong) NSArray *enabledDates;
/**
 *  Wether enabled dates will have different backgrounds (default) or show dots below them
 */
@property (nonatomic) CLEnabledDatesAppearance enabledDatesAppearance;
@property (nonatomic) BOOL disabledDatesInteractionEnabled;


- (void)redrawToDate: (NSDate *)dt;
- (void)updateWeatherIconByKey: (NSString *)key;

@end
