#CLWeeklyCalendarView

CLWeeklyCalendarView is a scrollable weekly calendarView for iPhone. It is easy to use and customised.

![alt tag](https://github.com/esusatyo/CLWeeklyCalendarView/blob/master/screenshot.PNG)

## Installation

Manually:

- Drag the `CLWeeklyCalendarViewSource` folder into your project.

## Initialize 

Using CLWeeklyCalendarViewSource in your app will usually look as simple as this :


```objective-c

//Initialize
-(CLWeeklyCalendarView *)calendarView
{
    if(!_calendarView){
        _calendarView = [[CLWeeklyCalendarView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, 100)];
        _calendarView.delegate = self;
    }
    return _calendarView;
}

//Add it into parentView
[self.view addSubview:self.calendarView];

```

## Delegate

After the date in the calendar has been selected , following delegate function will be fired

```objective-c
//After getting data callback

- (void)calendarView:(CLWeeklyCalendarView *)calendarView dailyCalendarViewDidSelect:(NSDate *)date {
{
    //You can do any logic after the view select the date
}
```

You can delegate to tell the calenderView scrollTo specified date by using following delegate function

```objective-c
- (void)redrawToDate: (NSDate *)dt;
```

## UI Customisation

**Please be aware customisation method is optional, if u do not apply it, it will just fire the default value.

The following customisation key is allowed:

```
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
extern NSString *const CLCalendarSelectedDayNumberBorderColor;  //Day number label border color for selected day
extern NSString *const CLCalendarSelectedCurrentDayNumberBackgroundColor;   //Day number background color when today is selected
extern NSString *const CLCalendarSelectedDatePrintFormat;   //Selected Date print format,  - Default: @"EEE, d MMM yyyy"
extern NSString *const CLCalendarSelectedDatePrintColor;    //Selected Date print text color -Default: [UIColor whiteColor]
extern NSString *const CLCalendarSelectedDatePrintFontSize; //Selected Date print font size - Default : 13.f
extern NSString *const CLCalendarBackgroundImageColor;      //BackgroundImage color - Default : see applyCustomDefaults.
extern NSString *const CLCalendarDisabledDayTextColor;      //Day number text color for disabled dates
extern NSString *const CLCalendarDisabledDayBackgroundColor;      //Day number background color for disabled dates
extern NSString *const CLCalendarFont; //Preferred font of the calendar UI, default to system font. Font size passed here is ignored.
```

You need to use this method to apply your customisation:

```objective-c

self.calendarView.calendarAttributes = @{
       CLCalendarBackgroundImageColor : [UIColor lightBackgroundColor],
       
       //Unselected days in the past and future, colour of the text and background.
       CLCalendarPastDayNumberTextColor : [UIColor lightGrayColor],
       CLCalendarFutureDayNumberTextColor : [UIColor lightGrayColor],
       
       CLCalendarCurrentDayNumberTextColor : [UIColor lightGrayColor],
       CLCalendarCurrentDayNumberBackgroundColor : [UIColor clearColor],
       
       //Selected day (either today or non-today)
       CLCalendarSelectedDayNumberTextColor : [UIColor whiteColor],
       CLCalendarSelectedDayNumberBackgroundColor : [UIColor primaryColor],
       CLCalendarSelectedCurrentDayNumberTextColor : [UIColor whiteColor],
       CLCalendarSelectedCurrentDayNumberBackgroundColor : [UIColor primaryColor],
       
       //Day: e.g. Saturday, 1 Dec 2016
       CLCalendarDayTitleTextColor : [UIColor darkGrayColor],
       CLCalendarSelectedDatePrintColor : [UIColor darkGrayColor],
       };

```

## Disabling Date Selections

If you call `setEnabledDates:` on `CLWeeklyCalendarView`, then it will make only the enabled dates to be selectable in the UI. This is useful if you only have content to show on particular days.

If you use this option, make sure to also set `CLCalendarDisabledDayBackgroundColor` or `CLCalendarDisabledDayTextColor` to indicate to the users that some dates aren't selectable.
