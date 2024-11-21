
#define NUMBER_CANDIDATES 5
#define STATES 51
#define NUMBER_OF_VOTERS 500

typedef struct {
    int stat;
    int pref;
} person;

typedef struct {
    int votes[NUMBER_CANDIDATES];
    int electors;
    int winner;
} states;


typedef enum {
    ALABAMA,
    ALASKA,
    ARIZONA,
    ARKANSAS,
    CALIFORNIA,
    COLORADO,
    CONNECTICUT,
    DELAWARE,
    FLORIDA,
    GEORGIA,
    HAWAII,
    IDAHO,
    ILLINOIS,
    INDIANA,
    IOWA,
    KANSAS,
    KENTUCKY,
    LOUISIANA,
    MAINE,
    MARYLAND,
    MASSACHUSETTS,
    MICHIGAN,
    MINNESOTA,
    MISSISSIPPI,
    MISSOURI,
    MONTANA,
    NEBRASKA,
    NEVADA,
    NEW_HAMPSHIRE,
    NEW_JERSEY,
    NEW_MEXICO,
    NEW_YORK,
    NORTH_CAROLINA,
    NORTH_DAKOTA,
    OHIO,
    OKLAHOMA,
    OREGON,
    PENNSYLVANIA,
    RHODE_ISLAND,
    SOUTH_CAROLINA,
    SOUTH_DAKOTA,
    TENNESSEE,
    TEXAS,
    UTAH,
    VERMONT,
    VIRGINIA,
    WASHINGTON,
    WEST_VIRGINIA,
    WISCONSIN,
    WYOMING,
    DISTRICT_OF_COLUMBIA
} state_names;

void america();
int calculate_winner(int *array);