#include <stdio.h>				//-----> Standard for printf function and others common function
#include <windows.h>			 //----> USe for Interact with window function use here desktop clr
#include <string.h>		         //----> USe for String Functions
#include <stdlib.h>              //---->USe for Memory Allocation and rand
#include <time.h>               //------> USe for Time Handling
#include <unistd.h>             //-----> USE for sleep function
#include<ctype.h>               //-----> Collection of functions to classify and transform characters.
#include<dirent.h>              //------>Used for directory operations like opening, reading, and closing directories.


#define MAX_CANDIDATES 15
#define MAX_LINE_LENGTH 256



//function declaration/prototo all which we have used
/*
for simple Usuage and Understanding Every task is divide into different funtion
taky changing reading and documentation me asaani ho
*/


 
void set_fixed_screen_size(int width, int height); // It can be use for Screen Size FIX
// Main Menu Functions
void display_main_menu();           // Main menu display function first Interface
void display_admin_menu();          // Admin portal options display function help for Admin Manaagment
void display_voting_menu();         //  portal Options display function

// Admin Portal Functions
void menu_call();
void view_past_results();           // View stored voting session results
void setup_session();               // USe for a session
void add_candidate();               // Add candidates to the session
void create_random_list();			// For that we include here system which ask for the path of the .csv file 
//where we have two columns already and third would be create this function with password name columns create random password
//start sub function of this task


//HEre these function are use for random password generation

//ALL CONSTANTSSSS which are not change: 
#define path_ki_maxlength 260 // path l
#define linemaxlength 1024
#define password_length 8
#define max_path 260
// Define the maximum lengths and file path
#define maxcandidate_no 15
#define maxname_leng 200
#define FILE_PATH "config.csv"
//admin Data
#define FILE_NAME "userdata.evs" 
#define KEY 0x4A // Simple XOR encryption key
int key=1; // use for handling processing

//configuration functions
//here these are important things which admin put and these data store in csv file then we conduct voting 

int config_main();                             //main USuage of the file
void get_position(char *position);			 // help to store Positon in CSVV file
void get_number_of_candidates(int *num_candidates); /// Help to Store NUMber of Candidates
void get_candidate_names(char candidate_names[][maxname_leng], int num_candidates);    // Name store of candidate throught this function
void get_voter_list_path(char *voter_list_path); // Voterr list path will store from this
int verify_path(const char *path);     // after path enter verification will be process from here and Fill the in the CSV file status 
void get_session_time(int *hours, int *minutes);      //Session timing 
int validate_configuration(int num_candidates, char candidate_names[][maxname_leng]);    // OVerall data configure and Verified from these
void save_configuration_to_csv(const char *position, int num_candidates, char candidate_names[][maxname_leng], /////SAVING
                               const char *voter_list_path, int is_verified, int hours, int minutes, int is_configured);/////SAVING


//THESE ARE STORING AND VERIFY THE PATHS OF THE FILES
//Help to find path through program and stoe it into the csv file
void listDrives();           //List of Drives Conduction
void listDirectories(const char *path); ////directries
void listCSVFiles(const char *path);   // list of CSV files
int changeDirectory(char *currentPath); //Change directories from these 
void goBackDirectory(char *currentPath);  // For GOBACK
void generatePassword(char *password); //Random Password Generation
int addPasswordColumnToCSV(const char *filePath); //ADD Passwords in the column of CSV file
int isValidDrive(char driveLetter);
void showMenu(char *currentPath);
void driveSelection(char *currentPath);

//config.cpp
//End 

//
//void upload_voter_list();           // Upload voter IDs,Names and passwords
//void set_session_time();            // Set start and end times for voting
//void view_current_results();        // View live results of an active session
//void edit_info();                   // Edit candidate or voter information
//void clear_data();                  // Clear previous session data or reset system
//void logout_admin();                // Log out admin and return to main menu
//void change_pass();


// Admin Passwords System
void encrypt_text(char *text);
//int  encrypt_text(char *text);
void write_data(const char *user, const char *pass, const char *q1, const char *q2, const char *q3);
int read_data(char *user, char *pass, char *q1, char *q2, char *q3);
//void write_data(const user,const char *q2, const char *q3);
void setup_account();   // setup 
void login(); //login 
void forget_password(); //forget passwordd
void setup(); //sETUP all
int admin_login();



// Voting Session Functions
//These are Getting Data from file and verify 
bool authenticate_voter(char *id, char *pwd); // Authenticate voter credentials
void show_auth_error();             // Show errorrr for failED voter authentication
void show_candidates();           // Display Candidates for voting
void cast_vote(char *id);           // Voter sSelects, confirms, and submits vote
void confirm_vote();               // Show CConfirmation message after voting
void logout_voter();                // Log outt voter after voting
void prevent_duplicate(char *id);   // Check and prevent duplicate voting

// Data Storage and Filesystem Functions
void store_vote(char *id, char *candidate, char *timestamp); // Log vote in CSV
void organize_files();              // Organize session files
void validate_input_files();        // Validate uploaded CSV files for errors
void handle_invalid_input();        // Handle unexpected inputs during voting

// Additional Functionalities
void encrypt_pwd(char *pwd);        // Encrypt password data through this function
bool admin_auth(char *id, char *pwd); // Admin login with optional 2FA       
void set_timeout();               // Auto-log out idle users
void log_admin_action(char *action, char *id); // Track admin actions in log
void backup_data();                // Back up session data after each session
void alert_session_end();           // Alert admin when session is near expiration
void limit_login_attempts(char *id); // Limit failed login attempts for voters
void log_error(char *error);      // Log errors during voting session
void confirm_vote_selection();      // Prompt for final vote confirmation
void show_help();               // Display help instructions to voters
void show_results_percentage();    // Show candidate results with percentage
void inactive_voter_reminder();     // Notify admin of inactive voters

// Session Management and Cleanup
void cleanup_data();                // Delete unnecessary old session files
void generate_summary();            // Generate a summary report after session

// Utility and Helper Functions
void log_time(char *action);        // Log timestamps for actions record 
void mask_pwd_input();              // Mask password on input when admin or voter login it will mask the password
void validate_csv();                // Validate CSV file format before upload if the input file can't contain 
//IDs Name and Password Column it will deny even if one id is dispair ID or CNIC we can here use string


// change the password 



void encrypt_text_1(char *text);
void write_data_2(const char *user, const char *pass, const char *q1, const char *q2, const char *q3);
int read_data_3(char *user, char *pass, char *q1, char *q2, char *q3);
void change_password_4();
void displayfake();//for fixing some display setting;

//END
// Current Session which was going to start about details
// Define the required columns
#define REQUIRED_COLUMNS_7 7
const char *COLUMN_NAMES[REQUIRED_COLUMNS_7] = {
    "POSITION",
    "NUMBER OF CANDIDATE",
    "CANDIDATES NAMES",
    "VOTER LIST PATH",
    "PATH VERIFICATION",
    "SESSION TIME",
    "CONFIGURATION STATUS"
};

const char *config_filename = "config.csv";

// Function prototypes
int validate_columns(char *header_line);
void parse_and_print_config(char *line);
void read_config_file(const char *filename);
void current_session ();


//END 
//SHOW THE Position of the Voting 
///#define MAX_LINE_LENGTH_FOR_PATH 256

// Function Declaration
void print_voting_position(const char *config_file_path); // Function parameter at the top
//END
//copy the files
void load_and_copy_modify_candidate_file(const char *config_file_path);
int dowhile=1;
void check_and_update_flag(const char *filename);
//

//start voting
//#define MAX_LINE_LENGTH 256
#define MAX_CANDIDATES 15
//Voting            finally        -->STart Voting Functions
// Function Prototypes
// Function Prototypes
// Function prototypes
// Function Prototypes
// Function Prototypes
#define MAX_CANDIDATES 15

// Function Prototypes
char* trim(char *str);
int load_voting_duration(int *hours, int *minutes);
int load_candidates(char candidate_names[][50]);
int count_ids();
int validate_user(const char *username, const char *password1);
void record_vote(const char *username, const char *candidate_name);
void initialize_time_log(int hours, int minutes);
void update_remaining_time(time_t start_time, int allowed_hours, int allowed_minutes);
void vote_in_election(time_t start_time, int allowed_hours, int allowed_minutes);
void main_login_voters();

int keynor=1;
//END voting

///functtion REsult Making
#define MAX_NAME_LEN 50
#define RESULT_PREFIX "result"

// Function prototypes
void create_voting_result();
void see_results();
int main_result();





///ENDDDD



int main() {
//	printf("Welcome to the Voting System");
//	set_fixed_screen_size(1000, 6000); 
	display_main_menu();  //Display EVS    
 // Display other information with stable coordinates
    return 0;
}
	int menu_option;
//function definitions
void display_main_menu() {
    system("cls");

    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t   EEEEEEEEEEE   VVV       VVV   SSSSSSSSS   \n");
    printf("\t\t\t\t\t   EEEEEEEEEEE   VVV       VVV  SSSSSSSSSSS   \n");
    printf("\t\t\t\t\t   EEE            VVV     VVV   SSS\n");
    printf("\t\t\t\t\t   EEE            VVV     VVV    SSS\n");
    printf("\t\t\t\t\t   EEEEEEEE        VVV   VVV      SSSSSSS\n");
    printf("\t\t\t\t\t   EEEEEEEE        VVV   VVV       SSSSSSS\n");
    printf("\t\t\t\t\t   EEE              VVV VVV             SSS\n");
    printf("\t\t\t\t\t   EEE              VVV VVV             SSS\n");
    printf("\t\t\t\t\t   EEEEEEEEEEE       VVVVV        SSSSSSSSS\n");
    printf("\t\t\t\t\t   EEEEEEEEEEE        VVV         SSSSSSSSS\n");

    printf("\n\n\t\t\t\t\t   Choose an option from the menu below:\n");
    printf("\t\t\t\t\t   ======================================\n");
    printf("\t\t\t\t\t   1. Start Voting\n");
    printf("\t\t\t\t\t   2. Admin Dashboard\n");
    printf("\t\t\t\t\t   3. Exit\n");   
    printf("\t\t\t\t\t   ======================================\n");

    while (1) {
        printf("\t\t\t\t\t   Enter Menu Option i.e 1, 2, 3 : ");
        
        if (scanf("%d", &menu_option) != 1) {
            printf("\t\t\t\t\t   Invalid Input. Please enter a valid option (1, 2, or 3).\n");
            printf("\t\t\t\t\t   Wait for a sec to enter the menu option again!\n");
            while (getchar() != '\n');
            sleep(2);
            display_main_menu(); 
            return;
        }

        if (menu_option == 1) {
            admin_login();
            return;
        } else if (menu_option == 2) {
            menu_call();
            return;
        } else if (menu_option == 3) {
            exit(0);
        } else {
            printf("\t\t\t\t\t   Invalid Input. Please enter a valid option (1, 2, or 3).\n");
            sleep(2);
            display_main_menu();  // Call the function again to re-display the menu
            return;
        }
    }
}

void display_admin_menu(){
		printf("\e[1;1H\e[2J");
		   system("cls");
    	printf("\n\n\t\t\t\t\t");
    	 printf("    _       _           _                          \n");printf("\t\t\t\t\t"); 
    printf("   / \\   __| |_ __ ___ (_)_ __                     \n");printf("\t\t\t\t\t"); 
    printf("  / _ \\ / _` | '_ ` _ \\| | '_ \\                   \n");printf("\t\t\t\t\t"); 
    printf(" / ___ \\ (_| | | | | | | | | | |                  \n");printf("\t\t\t\t\t"); 
    printf("/_/   \\_\\__,_|_| |_| |_|_|_| |_|                 \n");printf("\t\t\t\t\t"); 
    printf(" ____            _     _                         _ \n");printf("\t\t\t\t\t"); 
    printf("|  _ \\  __ _ ___| |__ | |__   ___   __ _ _ __ __| |\n");printf("\t\t\t\t\t"); 
    printf("| | | |/ _` / __| '_ \\| '_ \\ / _ \\ / _` | '__/ _` |\n");printf("\t\t\t\t\t"); 
    printf("| |_| | (_| \\__ \\ | | | |_) | (_) | (_| | | | (_| |\n");printf("\t\t\t\t\t"); 
    printf("|____/ \\__,_|___/_| |_|_.__/ \\___/ \\__,_|_|  \\__,_|\n");printf("\n\t\t\t\t\t"); 
	
printf("===================================================");
if(menu_option==1)
printf("\n\t\t\t\t\tBefore Starting the Voting Please Login to Verify : \n");
else
printf("\n\t\t\t\t\t   Setup the Dashboard below:\n");
printf("\t\t\t\t\t   ======================================\n");
}
void display_voting_menu(){
		printf("\e[1;1H\e[2J");
		   system("cls");
    	printf("\n\n\t\t\t\t\t\t");
       printf(" _    _          _                                    \n"); printf("\t\t\t\t\t\t");
    printf("| |  | |    _   (_)                                   \n");  printf("\t\t\t\t\t\t");
    printf("| |  | |__ | |_  _ ____   ____                        \n");  printf("\t\t\t\t\t\t");
    printf(" \\ \\/ / _ \\|  _)| |  _ \\ / _  |                       \n"); printf("\t\t\t\t\t\t");
    printf("  \\  / |_| | |__| | | | ( ( | |                       \n"); printf("\t\t\t\t\t\t");
    printf("   \\/ \\___/ \\___)_|_| |_|\\_|| |                       \n");printf("\t\t\t\t\t\t");
    printf("                        (_____|                       \n");printf("\t\t\t\t\t");
	 printf(" ____            _     _                         _ \n");printf("\t\t\t\t\t"); 
    printf("|  _ \\  __ _ ___| |__ | |__   ___   __ _ _ __ __| |\n");printf("\t\t\t\t\t"); 
    printf("| | | |/ _` / __| '_ \\| '_ \\ / _ \\ / _` | '__/ _` |\n");printf("\t\t\t\t\t"); 
    printf("| |_| | (_| \\__ \\ | | | |_) | (_) | (_| | | | (_| |\n");printf("\t\t\t\t\t"); 
    printf("|____/ \\__,_|___/_| |_|_.__/ \\___/ \\__,_|_|  \\__,_|\n");printf("\n\t\t\t\t\t"); 
	
printf("===================================================");
printf("\n\t\t\t\t\t\t");  print_voting_position("config.csv");
printf("\t\t\t\t\t      ======================================\n");
    if(dowhile)
    check_and_update_flag("flag.txt"); // Call function with the file name
    dowhile=0;
   
   main_login_voters();//

}


void menu_call() {
    display_admin_menu(); // Display the admin menu

    if (key == 1) {
        admin_login(); // If key is 1, call admin_login
    }

    int selection;

    // Display the menu options
    printf("\t\t\t\t\t   1. Voting Results\n");
    printf("\t\t\t\t\t   2. Configure Voting Session\n");
    printf("\t\t\t\t\t   3. Setup Unknown Password List\n");
    printf("\t\t\t\t\t   4. Session Details\n");
    printf("\t\t\t\t\t   5. Change Admin Password\n");
    printf("\t\t\t\t\t   6. Exit\n");
    printf("\t\t\t\t\t   ======================================\n");

    // Prompt the user to enter a menu option
    printf("\t\t\t\t\t   Enter Menu Option (1-6): ");
    
    // Check if the input is a valid integer
    if (scanf("%d", &selection) != 1) {
        printf("\t\t\t\t\t   Invalid input. Please enter a valid option (1-6).\n");
        while (getchar() != '\n'); // Clear the input buffer
        menu_call(); // Recursively call the function to re-prompt the user
        return; // Exit the function to prevent further code execution
    }

    // Handle the menu selection
    switch (selection) {
        case 1:
            main_result(); // Show the voting results
            break;
        case 2:
            config_main(); // Configure the voting session
            break;
        case 3:
            {
                char currentPath[max_path] = "";
                srand((unsigned int)time(NULL)); // Seed the random number generator
                driveSelection(currentPath); // Start the drive selection process for password list
            }
            break;
        case 4:
            current_session(); // Show the current session details
            break;
        case 5:
            change_password_4(); // Change the admin password
            break;
        case 6:
            display_main_menu(); // Exit and return to the main menu
            key = 1;
            break;
        default:
            printf("\t\t\t\t\t   Invalid option. Please enter a valid option (1-6).\n");
            menu_call(); // If the user selects an invalid option, recursively call the function again
            return; // Exit the function after re-prompting
    }
}



void create_random_list(){

}

///START PASSWORD RANDOM CREATOR 500^line no
// Function to list available drives
// Function to list available drives
void listDrives() {
    DWORD drives = GetLogicalDrives();
   // printf("\t\t\t\t\t   ======================================\n");
    printf("\t\t\t\t\t    Available Drives:\n");
    for (char i = 'A'; i <= 'Z'; i++) {
        if (drives & (1 << (i - 'A'))) {
            printf("\t\t\t\t\t    Drive: %c:\n", i);
        }
    }
}

// Function to list directories in the specified folder
void listDirectories(const char *path) {
    printf("\n\t\t\t\t\t  Directories in %s:\n", path);

    WIN32_FIND_DATA findFileData;
    char searchPath[max_path];
    snprintf(searchPath, max_path, "%s\\*", path);

    HANDLE hFind = FindFirstFile(searchPath, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("\t\t\t\t\t  Error finding directories.\n");
        sleep(2);
        return;
    }

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
                printf("\t\t\t\t\t  Directory: %s\n", findFileData.cFileName);
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);
	sleep(2);
	printf("\t\t\t\t\t  Waiting for 5 sec (note the name of directory) ");
	sleep(7);
    FindClose(hFind);
}

// Ffunction to listt .csv filess in the specified folder
void listCSVFiles(const char *path) {
printf("\n\t\t\t\t\t      CSV Files in %s:\n\t\t\t\t\t      ", path);

    WIN32_FIND_DATA findFileData;
char searchPath[max_path];
    snprintf(searchPath, max_path, "%s\\*.csv", path);   //print path krny ky liye

    HANDLE hFind = FindFirstFile(searchPath, &findFileData);       

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("\t\t\t\t\t\t  No CSV files found in the current directory.\n");       
        sleep(2); // screen stop for 2sec here
        return;
    }

    int count = 0;
    do {
        printf("\t\t\t\t\t      %d. %s\n", ++count, findFileData.cFileName);
    } while (FindNextFile(hFind, &findFileData) != 0);
//    FindClose(hFind, FindData);

    FindClose(hFind);
    if (count == 0) {
    printf("\t\t\t\t\tNo CSV files found in the current directory.\n");
sleep(2);
        return;
    }

    // Allow user to select a file
int fileChoice;
    printf("\t\t\t\t\t      Enter the number of the CSV file to modify: ");
    scanf("%d", &fileChoice);
	sleep(2);
hFind = FindFirstFile(searchPath, &findFileData);
    for (int i = 1; i < fileChoice && FindNextFile(hFind, &findFileData); i++);

    if (fileChoice <= 0 || findFileData.cFileName[0] == '\0') {
        printf("\t\t\t\t\t Invalid selection.\n");
        sleep(2);
        FindClose(hFind); //closing the file
        return;
    }

    char selectedFile[max_path]; //selected file path 
    snprintf(selectedFile, max_path, "%s\\%s", path, findFileData.cFileName);

    // Add password column and save to the same directory
    if (addPasswordColumnToCSV(selectedFile) == 0) {
printf("\t\t\t\t\tPassword column added successfully to %s.\n", selectedFile);
        sleep(2);
    }

    FindClose(hFind);
}

// Function to generate a random 8-character password
void generatePassword(char *password) {
const char *charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
	//through thiswe generate random password 
	//srand use for that
	//rand for Random PASSword 
    for (int i =0; i< password_length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[password_length] = '\0';//Null Character at the EnD
}

// Function to add a password column to the CSV file (only to the 3rd column)
int addPasswordColumnToCSV(const char *filePath) {
    
	FILE *file = fopen(filePath, "r"); //OPen the File as r mode
if (file == NULL) { //if file is Null
    printf("\t\t\t\t\t Error opening the CSV file at %s.\n", filePath);
        return -1;
    }

    //checking
	FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
       fclose(file);
    return -1;
    }

char line[linemaxlength];
char password[password_length + 1];
    int isFirstRow = 1;

    // Process With tHE CSV line by line
    while (fgets(line, sizeof(line), file)) {
        // If it's the header row Just copy it
        if (isFirstRow) {
        fputs(line, tempFile);
            isFirstRow = 0;
        } else {
        // the Generation pass ANDD append it to the third column
            generatePassword(password);

            // Splitt  the line into (columns) and reconstructtt the lineee with password in the third column
            char *token = strtok(line, ",");
            char newLine[linemaxlength] = "";
            int colCount = 0;

            // Itterate tHrough each column Preserving the first two columns (ID and Name)
            while (token != NULL) {
                // Keep the ID and Name columns as they are
                if (colCount == 2) {  // This ISSS the third column (Passwords) idhar hy password
                    strcat(newLine, ",");
                    strcat(newLine, password);  // Add password to the third column ---> through ConaAtnate 
                    break;
                }

                if (colCount > 0) {  // Add commas for the other columns-----> throught string concatinate Function
                    strcat(newLine, ",");
                }

                strcat(newLine, token);
                colCount++;
                token = strtok(NULL, ",");
            }

            // ADD append the new ------------>  temporary file
            strcat(newLine, "\n");
            fputs(newLine, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Replace the original CSV with the updated one
    if (remove(filePath) != 0 || rename("temp.csv", filePath) != 0) {
        printf("\t\t\t\t\t  Error updating the CSV file.\n");
        return -1;
    }

    return 0;
}

// --------> Validation of the Drive ----Function to check if the selected drive is valid
int isValidDrive(char driveLetter) {
    char drivePath[4];//
    snprintf(drivePath, sizeof(drivePath), "%c:\\", driveLetter);

DWORD attributes = GetFileAttributes(drivePath);
    return (attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY)); //return the directory

}

//---> HandLING of the File --- handle the drive selection
void driveSelection(char *currentPath) {
    char driveLetter;
    while (1) {
        printf("\t\t\t\t\t   Select a Drive:\n");
        listDrives();
        printf("\t\t\t\t\t    Enter drive letter (e.g., C): ");
        
        // Read a character and ensure that it is valid
        int result = scanf(" %c", &driveLetter);
        
        // Check if the input is a valid character and the input was not empty
        if (result != 1 || driveLetter < 'A' || driveLetter > 'Z') {
            printf("\n\t\t\t\t\t Invalid input. Please enter a valid drive letter (A-Z).\n");
            printf("\n\t\t\t\t\t Now wait for a sec!");
            sleep(1);
            system("cls");
            display_admin_menu();
            displayfake();
        } else if (isValidDrive(driveLetter)) {
            snprintf(currentPath, max_path, "%c:\\", driveLetter);
            break;  // Exit loop when a valid drive is selected
        } else {
            printf("\n\t\t\t\t\t Invalid drive letter, Please try again.\n");
            sleep(1);
            system("cls");
            display_admin_menu();
            displayfake();
        }
    }

    showMenu(currentPath);
}



// Recursive-----> menu function
void showMenu(char *currentPath) {
    int choice;
    
    display_admin_menu();
    printf("\n\t\t\t\t\t    Current Directory: %s\n", currentPath);
    printf("\t\t\t\t\t    Options:\n");
    printf("\t\t\t\t\t      1. List Directories\n");
    printf("\t\t\t\t\t      2. List CSV Files\n");
    printf("\t\t\t\t\t      3. Enter a Directory\n");
    printf("\t\t\t\t\t      4. Go Back to Parent Directory\n");
    printf("\t\t\t\t\t      5. Change Drive\n");
    printf("\t\t\t\t\t      6. Exit\n");
    printf("\t\t\t\t\t      Enter your choice: ");
    
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf("\n\t\t\t\t\t Invalid input. Please enter a valid number.\n");
        sleep(1);
        system("cls");
        showMenu(currentPath);
        return;
    }
    
    switch (choice) {
        case 1:
            listDirectories(currentPath);
            break;
        case 2:
            listCSVFiles(currentPath);
            break;
        case 3:
            if (changeDirectory(currentPath) == -1) {
                printf("\t\t\t\t\t Failed to change directory. Please try again.\n");
            }
            break;
        case 4:
            goBackDirectory(currentPath);
            break;
        case 5:
            driveSelection(currentPath);
            break;
        case 6:
            menu_call();
            break;
        default:
            printf("\n\t\t\t\t\t Invalid choice. Please try again.\n");
            sleep(2);
            system("cls");
            showMenu(currentPath);
            return;
    }
    
    showMenu(currentPath);
}


// Function to change the current directory
int changeDirectory(char *currentPath) {
    char newPath[max_path];
    printf("\t\t\t\t\t Enter the path to change to: ");
    scanf("%s", newPath);
/*

    DWORD attributes = GetFileAttributes(newPath);
    if (attribute == INVALID_FILE_ATTRIBUTES) {
        printf("\t\t\t\t\t Error: Path does not exist.\n");
        return -;
    }

*/



    DWORD attributes = GetFileAttributes(newPath);
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        printf("\t\t\t\t\t Error: Path does not exist.\n");
        return -1;
    }

    if (!(attributes & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("\t\t\t\t\t Error: Not a directory.\n");
        return -1;
    }

strncpy(currentPath, newPath, max_path);
    return 0;
}

// GoBack to Parent Directory -------->Function to go back to the parent directory
void goBackDirectory(char *currentPath) {
    char *lastBackslash = strrchr(currentPath, '\\');
    if (lastBackslash != NULL && lastBackslash != currentPath + 2) {
        *lastBackslash = '\0'; 
    } else {
        currentPath[0] = '\0';  // Goback to the root of the drive
    }
}
///END PASSWORD RANDOM CREATOR 


///configuration

 
int config_main(){
	// this are the Variables to store input data -------> Configue
    char position[50];
    int num_candidates;
    char candidate_names[MAX_CANDIDATES][maxname_leng];
    char voter_list_path[256];
    int hours, minutes;
    int is_verified = 0;
    int is_configured = 0;
	int k = 0;
	char per;
	
	for(k=0;k!=2;){
	if(k==1)
	{
	display_admin_menu();
	config_main();	
	}
    // Get inputs--->Separatelyyy
    get_position(position);
    get_number_of_candidates(&num_candidates);
    get_candidate_names(candidate_names, num_candidates);
    get_voter_list_path(voter_list_path);

    // Verify the path USIng this Funciton
    is_verified = verify_path(voter_list_path);

    if (is_verified) {
        get_session_time(&hours, &minutes);
        
        // Validate --? configuration
        is_configured = validate_configuration(num_candidates, candidate_names);
        
    // Save configuration to CSV file
        save_configuration_to_csv(position, num_candidates, candidate_names, voter_list_path, is_verified, hours, minutes, is_configured);
        
        printf("\n\t\t\t\t  Configuration saved successfully!\n ");
        menu_call(); //Again MENUUUU CALLL
        getchar();
        k=2;
    } 
else {
        printf("\n\t\t\t\t\t    Error: Voter list path verification failed.\n");
        printf("\t\t\t\t\t    Do you try again config Y/N : ");
        scanf("%c",&per);
        k=1;
        if(per=='N'|| per=='n')
       	menu_call();
        
    }
    
	}
    return 0;
	
}
void displayfake(){
		printf("\t\t\t\t\t   1. Voting Results\n");
    			printf("\t\t\t\t\t   2. Configure Voting Session\n");
    			printf("\t\t\t\t\t   3. Setup Unknown Password List\n");
    			printf("\t\t\t\t\t   4. Session Details\n");
   				printf("\t\t\t\t\t   5. Change Admin Password\n");
    			printf("\t\t\t\t\t   6. Exit\n");
    			printf("\t\t\t\t\t   ======================================\n");
}



// Function to get the position
void get_position(char *position) {
  //  printf("\t\t\t\t\t    Requirements:\n");
  
	printf("\t\t\t\t        Name a Position for candidates are running: ");
    getchar();
//     fget(positions, 50, stdin);
   
	fgets(position, 50, stdin);
    position[strcspn(position, "\n")] = '\0'; // Remove newline
}

// Function to get the number of candidates
void get_number_of_candidates(int *num_candidates) {
    int flag = 0;

    while (!flag) {
        printf("\t\t\t\t         Enter the number of candidates: ");
        
        if (scanf("%d", num_candidates) == 1) {
            int random = *num_candidates;
            if (random > MAX_CANDIDATES || random < 0) {
                printf("\n\t\t\t\t           Invalid Input. Number must be between 0 and %d.\n", MAX_CANDIDATES);
                printf("\t\t\t\t           Please try again...\n");
                sleep(2);
                system("cls"); 
                display_admin_menu();
    			displayfake();
                config_main();
                flag = 0;
            } else {
                flag = 1;
            }
        } else {
            printf("\n\t\t\t\t           Invalid Input. Please enter a valid integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            sleep(2);
            system("cls"); // Clear screen
            display_admin_menu();
            displayfake();
             config_main();
            flag = 0;
        }
    }
 

    getchar(); // This is USe for ---->  consume the newline left by scanf
}


//function USE to get candidate NAMEs 
void get_candidate_names(char candidate_names[][maxname_leng], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("\t\t\t\t         Enter name of candidate %d: ", i + 1);
        fgets(candidate_names[i], maxname_leng, stdin);
//    candidate_names[i][strcspn(candidate_names, "\n")] = '\0'; // Remove newline
//   
	    candidate_names[i][strcspn(candidate_names[i], "\n")] = '\0'; // Remove newlin    
	
	}
}

// vote lisT PAHT -----> Function voter list path
void get_voter_list_path(char *voter_list_path) {
    printf("\n\t\t\t\t         Enter path of voter list CSV file i.e D:\\3uToolsV3\\list.csv : ");
    fgets(voter_list_path, 256, stdin);
    voter_list_path[strcspn(voter_list_path, "\n")] = '\0'; // Remove newwwwline
}

// vERIFY the voter list CSV file
int verify_path(const char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return 0; // Path is invalid
    }

    // Read--------------> FIRST LINE TO CHECK number of columns
    char line[256];
    fgets(line, sizeof(line), file);
    fclose(file);
//
//    int columns = 0; 
//    for (int i = 1; line[i] != '\0'; i++) {
//        if (line[i] == ',') {
//            columns++;
//        }

// Count columns by commas in the first line
    int columns = 1; // Start with 1 column
    for (int i =0; line[i]!='\0'; i++) {
        if (line[i] == ',') {
            columns++;
}
    }

    return columns == 3 ? 1 : 0; // Verify if there are 3 columns
}

// session tiME SAVE THROUGH these function
void get_session_time(int *hours, int *minutes) {
    printf("\t\t\t\t         Enter session duration (hours minutes): ");
    scanf("%d %d", hours, minutes);
    sleep(1);
    printf("\t\t\t\t         Successfully Done Configuration ");
    sleep(1);
}

// Function to validate configuration
int validate_configuration(int num_candidates, char candidate_names[][maxname_leng]) {
    if (num_candidates <= 0) return 0;
    for (int i= 0; i <num_candidates; i++) {
        if (strlen(candidate_names[i]) == 0) return 0;
    } 
    return 1;
}

// Function to save configuration to a CSV file
void save_configuration_to_csv(const char *position, int num_candidates, char candidate_names[][maxname_leng], 
                               const char *voter_list_path, int is_verified, int hours, int minutes, int is_configured) {
    FILE *file = fopen(FILE_PATH, "w");
    if (file == NULL) {//Again checking for NULl
       printf("\t\t\t\t         Error: Could not open file to save configuration.\n");
       return;
    }

    fprintf(file, "POSITION,NUMBER OF CANDIDATE,CANDIDATES NAMES,VOTER LIST PATH,PATH VERIFICATION,SESSION TIME,CONFIGURATION STATUS\n");
    fprintf(file, "%s,%d,", position, num_candidates);

    // Add candidate names -->single cell separated by semicolons
    for (int i = 0; i < num_candidates; i++) {
        fprintf(file, "%s", candidate_names[i]);
        if (i < num_candidates - 1) {
            fprintf(file, ";");
        }
    }
    fprintf(file, ",%s,%s,%02d:%02d,%s\n", 
            voter_list_path, 
        is_verified ? "YES" : "NO", 
            hours, minutes, 
        is_configured ? "YES" : "NO");

    fclose(file);
}


//ENDDD Configuration
//ADdmin Login Page system

int admin_login() {
    display_admin_menu();
    setup();

    int choice;
    
    printf("\t\t\t\t\t    Menu:\n\t\t\t\t\t    1. Login\n\t\t\t\t\t    2. Forget Password\n\t\t\t\t\t    3. Exit\n\t\t\t\t\t    Choose an option: ");
    if (scanf("%d", &choice) != 1) {
        printf("\t\t\t\t\t    Invalid input. Please choose 1, 2, or 3.\n");
        while (getchar() != '\n');
        sleep(2);
        admin_login();
        return 0;
    }

    switch (choice) {
        case 1:
            login();
            return 0;
        case 2:
            forget_password();
            return 0;
        case 3:
            display_main_menu();
            return 0;
        default:
            printf("\t\t\t\t\t    Invalid option. Please choose 1, 2, or 3.\n");
            sleep(2);
            admin_login();
            return 0;
    }
}


// Function definitions
//ENCRYPTNG TEXT----> csv file me upload kry gy
void encrypt_text(char *text) {
    for (int i = 0; i < strlen(text); i++) {
        text[i] ^= KEY;
    }
}

void write_data(const char *user, const char *pass, const char *q1, const char *q2, const char *q3) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
     printf("\t\t\t\t\t    Error creating file.\n");
       return;
    }
	//COPY FIRST TIME BCZ it is not present
    char user_enc[100], pass_enc[100], q1_enc[100], q2_enc[100], q3_enc[100];
    strcpy(user_enc, user); //USE for Copy
    strcpy(pass_enc, pass);//use for copy
    strcpy(q1_enc, q1);//use for copy
    strcpy(q2_enc, q2);//use for copy
    strcpy(q3_enc, q3);//use for copy

    // Encrypt -------> each string
    encrypt_text(user_enc);
    encrypt_text(pass_enc);
    encrypt_text(q1_enc);
    encrypt_text(q2_enc);
    encrypt_text(q3_enc);
fprintf(file, "%s\n%s\n%s\n%s\n%s\nYES", user_enc, pass_enc, q1_enc, q2_enc, q3_enc);//-------->?Printing on the csv file
    fclose(file);
}
/*

int read_data(char *user, char *pass, char *q1, char *q2, char *q3) {
FILE file = fopen(FILE_NAME, "r+");
    if (!file) {
return 0; // File not found, so we need to set up
    }



*/



int read_data(char *user, char *pass, char *q1, char *q2, char *q3) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        return 0; //--> File not found
}
	
    fscanf(file, "%s\n%s\n%s\n%s\n%s\n", user, pass, q1, q2, q3);

    // Decrypt each string
    encrypt_text(user);
    encrypt_text(pass);
    encrypt_text(q1);
    encrypt_text(q2);
    encrypt_text(q3);

    fclose(file);
    return 1; // Data read successfully
}

void setup_account() {
    char user[100], pass[100], q1[100], q2[100], q3[100];
    printf("\t\t\t\t\t    First time setup:\n");
    printf("\t\t\t\t\t    Enter a username: ");
    scanf("%s", user);
   printf("\t\t\t\t\t    Enter a password: ");
    scanf("%s", pass);
    printf("\t\t\t\t\t    Security Question 1: What is 25 + 17? ");
    scanf("%s", q1);
    printf("\t\t\t\t\t    Security Question 2: What was the name of your first pet? ");
    scanf("%s", q2);
printf("\t\t\t\t\t    Security Question 3: What is your favorite 6 digit number? ");
    scanf("%s", q3);

    write_data(user, pass, q1, q2, q3);
    printf("\t\t\t\t\t    Setup complete. You can now log in.\n");
    admin_login();
}

void login() {
    char user[100], pass[100];
    char stored_user[100], stored_pass[100], q1[100], q2[100], q3[100];

    if (!read_data(stored_user, stored_pass, q1, q2, q3)) {
        printf("\t\t\t\t\t    Invalid data or file missing. Please re-setup.\n");
        setup_account();
        return;
    }

    while (1) {  // Loop until correct credentials are entered
        printf("\t\t\t\t\t    Enter username: ");
        scanf("%s", user);
        printf("\t\t\t\t\t    Enter password: ");
        scanf("%s", pass);

        if (strcmp(user, stored_user) == 0 && strcmp(pass, stored_pass) == 0) {
            printf("\t\t\t\t\t    Login successful!\n");
            sleep(2);
            if (menu_option == 2) {
                key = 0;
                menu_call();
            } else {
                display_voting_menu();
            }
            return;  // Exit the function when login is successful
        } else {
            printf("\t\t\t\t\t    Invalid username or password. Please try again.\n");
            sleep(2);
            system("cls"); 
            admin_login();
        }
    }
}


void forget_password() {
    char ans1[100], ans2[100], ans3[100];
    char stored_user[100], stored_pass[100], q1[100], q2[100], q3[100];

    if (!read_data(stored_user, stored_pass, q1, q2, q3)) {
    printf("\t\t\t\t\t    No data found. Please set up an account first.\n");
    sleep(2);
    setup_account();
    return;
    }

    printf("\t\t\t\t\t    Answer security questions to reset your password:\n");
    printf("\t\t\t\t\t    Question 1: What is 25 + 17? ");
    scanf("%s", ans1);
    printf("\t\t\t\t\t    Question 2: What was the name of your first pet? ");
    scanf("%s", ans2);
    printf("\t\t\t\t\t    Question 3: What is your favorite 6 digit number? ");
    scanf("%s", ans3);

    if (strcmp(ans1, q1) == 0 && strcmp(ans2, q2) == 0 && strcmp(ans3, q3) == 0) {
        printf("\t\t\t\t\t    Answers verified! Enter a new password: ");
        scanf("%s", stored_pass);
        write_data(stored_user, stored_pass, q1, q2, q3);
        printf("\t\t\t\t\t    Password reset successful.\n");
        sleep(2);
        admin_login();
    } else {
        printf("\t\t\t\t\t    Security answers incorrect. Access denied.\n");
        sleep(2);
        admin_login();
    }
}

void setup() {
    // CHECK THAT SETUP IS NEEDED OR NOT-
    FILE *file_check = fopen(FILE_NAME, "r");
    if (!file_check) {
        printf("\t\t\t\t\t    No setup data found. Initiating setup.\n");
        sleep(2);
        setup_account();
    } else {
        fclose(file_check);
    }
}



//END ADMIN login page systen

// Change password Function definitions

// Encrypts or decrypts --------->  XOR with KEY
void encrypt_text_1(char *text) {
    for (int i = 0; i < strlen(text); i++) {
        text[i] ^= KEY;
    }
}

// Writes encrypted user data on a ------->FILE
void write_data_2(const char *user, const char *pass, const char *q1, const char *q2, const char *q3) {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("\t\t\t\t\t Error creating file.\n");
        return;
    }
	//sAme as we doing copy
    char user_enc[100], pass_enc[100], q1_enc[100], q2_enc[100], q3_enc[100];
    strcpy(user_enc, user);
    strcpy(pass_enc, pass);
    strcpy(q1_enc, q1);
    strcpy(q2_enc, q2);
    strcpy(q3_enc, q3);

    // Encrypt each string
    encrypt_text_1(user_enc);
    encrypt_text_1(pass_enc);
    encrypt_text_1(q1_enc);
    encrypt_text_1(q2_enc);
    encrypt_text_1(q3_enc);

    fprintf(file, "%s\n%s\n%s\n%s\n%s\n", user_enc, pass_enc, q1_enc, q2_enc, q3_enc);
    fclose(file);
}

// Reads encrypted user data ----> FROM file and decrypts it
int read_data_3(char *user, char *pass, char *q1, char *q2, char *q3) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        return 0; // File not found IFFFFFF
    }

    fscanf(file, "%s\n%s\n%s\n%s\n%s\n", user, pass, q1, q2, q3);

    ///decrypt each string
    encrypt_text_1(user);
    encrypt_text_1(pass);
    encrypt_text_1(q1);
    encrypt_text_1(q2);
    encrypt_text_1(q3);

    fclose(file);
    return 1; // Data READ ---->  successfully
}

// Handles changing ----->  user's password
void change_password_4() {
    char old_pass[100], new_pass[100], choice;
    char stored_user[100], stored_pass[100], q1[100], q2[100], q3[100];

    // Check-----AS data file exists and read current user data
    if (!read_data_3(stored_user, stored_pass, q1, q2, q3)) {
        printf("\t\t\t\t\t Data file not found. Please contact the administrator.\n");
        return;
    }

    while (1) {
    	display_admin_menu();
        printf("\t\t\t\t\t Enter your current password: ");
        scanf("%s", old_pass);

        // Verify the OLDD password
        if (strcmp(old_pass, stored_pass) == 0) {
            printf("\t\t\t\t\t Enter a new password: ");
            scanf("%s", new_pass);

            // Update ----------> password and write back the data
            write_data_2(stored_user, new_pass, q1, q2, q3);
            printf("\t\t\t\t\t Password changed successfully...\n");
            sleep(2);
            menu_call();
            break;
        } else {
        printf("\t\t\t\t\t Current password does not match.\n");
        printf("\t\t\t\t\t Do you want to try again? (Y/N): ");
        scanf(" %c", &choice);

            if (choice == 'N' || choice == 'n') {
                printf("\t\t\t\t\t Exiting without changing the password...\n");
                sleep(2);
                menu_call();
                break;
            }
    }
    }
}



//END change password Setup

//Session_Current Output 







// Function to check ----------> all required columns exist in the header
int validate_columns(char *header_line) {
    for (int i =0; i< REQUIRED_COLUMNS_7; i++) {
    if (strstr(header_line, COLUMN_NAMES[i]) == NULL) {
            return 0; // Column not found-
        }
    }
    return 1; // All columns found------->FOUND CORRECTLY
}

// Function to parse and print configuration data from a line
void parse_and_print_config(char *line) {
    // TOKEMNIXE and parse each field
    char *position = strtok(line, ",");
    char *num_candidates = strtok(NULL, ",");
    char *candidates_names = strtok(NULL, ",");
    char *voter_list_path = strtok(NULL, ",");
    char *path_verification = strtok(NULL, ",");
    char *session_time = strtok(NULL, ",");
    char *config_status = strtok(NULL, ",");

    // Print the parsed data ------> required format
    printf("\t\t\t\t\t   POSITION: %s\n", position);
    printf("\t\t\t\t\t   NUMBER OF CANDIDATES : %s\n", num_candidates);
    printf("\t\t\t\t\t   CANDIDATES NAMES :\n");

    // Print EACh candidate Name
    char *candidate = strtok(candidates_names, ";");
    while (candidate != NULL) {
        printf("\t\t\t\t\t   %s\n", candidate);
        candidate = strtok(NULL, ";");
    }

    printf("\t\t\t\t\t   VOTER LIST PATH : %s\n", voter_list_path);
    printf("\t\t\t\t\t   PATH CORRECTION : %s\n", path_verification);
    printf("\t\t\t\t\t   Is all things Correct for SESSION : %s\n", config_status);
}

// Function tconfiguration 
//
//void read_config_file(const char filename) {
//    FILE file = fopen(file_name, "r");
//    if (file == NULL) {
//        printf("\t\t\t\t\t   The %s file doesn't exist.\n", filename);
//        return;
//    }

void read_config_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\t\t\t   The %s file doesn't exist.\n", filename);
        return;
    }

    char line[1024];
    
    // Read the header(means woh pehli row wali line) line ---->validate columns
    if (fgets(line, sizeof(line), file) == NULL || !validate_columns(line)) {
     printf("\t\t\t\t\t   Error: Required columns are missing in %s.\n", filename);
    fclose(file);
        return;
    }

    // Read the data line and parse it
    if (fgets(line, sizeof(line), file) != NULL) {
    parse_and_print_config(line);
    } else {
printf("\t\t\t\t\t   Error: No data row found in %s.\n", filename);
    }
    fclose(file);
}

// Main functio-- fon CurrentSession
void current_session() {
    read_config_file(config_filename);
    printf("\t\t\t\t\t   Press Enter for Back to Admin Dashboard");
    sleep(5);
	getchar();
	getchar();
    menu_call();
}



///END THE FUNCTION Definitions


//POSITION SHOWING 

void print_voting_position(const char *config_file_path) {
    FILE *file = fopen(config_file_path, "r");
    if (file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to open config file.\n");
        return;
    }
//void print_voting_position(const char *config_file_path) {
//    FILE *file = fopen(config_file_path, "r");
//    if (file == NULL) {
//        printf("Error: Unable to open config file.\n");
//        return;
//    }



    char line[linemaxlength];
    
    // Skip -----> header line/ First Row
    fgets(line, sizeof(line), file);
    
    // Read the second row (which is actually the first row after the header)
    if (fgets(line, sizeof(line), file) != NULL) {
    char position_text[50];
        
    // Extract the text from the first column of this line UU know this is postion
    sscanf(line, "%[^,]", position_text); // Read up to the first comma
        
        // Print the position with the specified message
	printf("Voting for this Position: %s\n", position_text);
    } 
	
	else {
        printf("\t\t\t\t\t   Error: Second row not found in the file.\n");
    }

    fclose(file);
}



//END POSITION

//load file as copy

//
// Function to LOAD  the CANDIDATE file path from config.csv and modify it
void load_and_copy_modify_candidate_file(const char *config_file_path) {
    char candidate_file_path[max_path];
    
    // Open config file to read the candidate file path------> pROPERLY
    FILE *config_file = fopen(config_file_path, "r");
    if (config_file == NULL) {
        printf("\t\t\t\t\t   Please Setup Correctly - You Doing Mistakes....");
        sleep(3);
       display_main_menu();
    }

    char line[500];
    int row = 0;
    while (fgets(line, sizeof(line), config_file)) {
        if (row == 1) {  // Read the second row (index 1), which contains file paths
            // Extract the path from column 4
            sscanf(line, "%*[^,],%*[^,],%*[^,],%[^,\n]", candidate_file_path);
            break;
        }
        row++;
    }
    fclose(config_file);

    // Path----FOR modified file
    char dest_path[max_path] = "results\\copy_of_candidates.csv";

    // Open source and destination fileS
    FILE *source_file = fopen(candidate_file_path, "r");
    if (source_file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to open source candidate file.\n");
        printf("\t\t\t\t\t   Please Setup Correctly - You Doing Mistakes....");
        sleep(3);
       display_main_menu();
    }

    FILE *dest_file = fopen(dest_path, "w");
    if (dest_file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to create destination file.\n");
        printf("\t\t\t\t\t   Please Setup Correctly -  You doing Mistakes...");
        fclose(source_file);
        sleep(3);
        display_main_menu();

    }

    // Copy each LIine and add newW columns
    int is_header = 1;
    while (fgets(line, sizeof(line), source_file)) {
        if (is_header) {
            // Add headers/PEHLI ROW for Vote Status and CANDIDATE SELECTED columns
            fprintf(dest_file, "%s,Vote Status,CANDIDATE SELECTED\n", strtok(line, "\n"));
            is_header = 0;
        } 
		
	else {
            // Copy each row and add default values for new columnsS
            fprintf(dest_file, "%s,NOT VOTED,Not Selected\n", strtok(line, "\n"));
       }
    }

    fclose(source_file);
    fclose(dest_file);

    printf("\t\t\t\t\t   Successfully Created File\n");
    sleep(3);
}

//END

void check_and_update_flag(const char *filename) {
    FILE *file = fopen(filename, "r+"); // Open file ----> read/write mode
    if (file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to open the file %s.\n", filename);
    printf("\t\t\t\t\t   File is missing.\n");
    sleep(3);
       display_main_menu();
    }

    int flag;
    if (fscanf(file, "%d", &flag) != 1) { // Check ----> reading is successful
       printf("\t\t\t\t\t   Error: Invalid flag value in file.\n");
    fclose(file);
    sleep(3);
       display_main_menu();
    }

    if (flag == 1) {
       main_login_voters();
    } else if (flag == 0) {
        printf("\t\t\t\t\t   Please check the result before starting new voting.\n");
        char choice;
        printf("\t\t\t\t\t   Do you want to start voting again? (Y/N): ");
        scanf(" %c", &choice); // Read user input

        if (choice == 'Y' || choice == 'y') {
            // Reset flag to 1 to -------> start new voting process
            fseek(file, 0, SEEK_SET);
            fprintf(file, "1");
             load_and_copy_modify_candidate_file(config_filename);

           main_login_voters(); 
        } else {
            printf("\t\t\t\t\t   Returning to main menu...\n");
            sleep(3);
            display_main_menu();
        }
    } else {
        printf("\t\t\t\t\t   Invalid Result Issue file \n");
     display_main_menu();
    }

    fclose(file); // Close the file
}




//END THE VOTING 


//login start voting 

// Trim function
char* trim(char *str) {
    while (isspace(*str)) str++;
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = 0;
    return str;
}

// Load voting duration from config.csv (hours and minutes)
int load_voting_duration(int *hours, int *minutes) {
    FILE *config_file = fopen("config.csv", "r");
    if (config_file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to open config file.\n");
        return 0;
    }

    char line[256];
    fgets(line, sizeof(line), config_file); // Skip header
    fgets(line, sizeof(line), config_file);

    char *duration = strtok(line, ",");
    for (int i = 0; i < 5; i++) duration = strtok(NULL, ","); // Move to duration field

    sscanf(trim(duration), "%d:%d", hours, minutes); // Parse hours and minutes

    fclose(config_file);
    return 1;
}

// Initialize time log file with hours and minutes (one-time creation)
void initialize_time_log(int hours, int minutes) {
    FILE *file = fopen("time_log.txt", "r");
    if (file == NULL) {
        file = fopen("time_log.txt", "w");
        fprintf(file, "%d:%d\n", hours, minutes);
        fclose(file);
    } else {
        fclose(file);
    }
}
int founder=0;
// Update remaining voting time in time_log.txt (hours and minutes)
void update_remaining_time(time_t start_time, int allowed_hours, int allowed_minutes) {
    time_t current_time = time(NULL);
    double elapsed_seconds = difftime(current_time, start_time);

    int total_allowed_seconds = (allowed_hours * 3600) + (allowed_minutes * 60);
    int remaining_seconds = total_allowed_seconds - (int)elapsed_seconds;

    if (remaining_seconds <= 0) {
        printf("\n\t\t\t\t\t   Voting closed. Time limit reached.\n");
        sleep(5);
        display_main_menu();
        return;
    }

    int remaining_hours = remaining_seconds / 3600;
    int remaining_minutes = (remaining_seconds % 3600) / 60;

    FILE *file = fopen("time_log.txt", "w");
    fprintf(file, "%d:%d\n", remaining_hours, remaining_minutes);
    fclose(file);
  //  if(!founder){
	
	
       system("cls");
    	printf("\n\n\t\t\t\t\t\t");
       printf(" _    _          _                                    \n"); printf("\t\t\t\t\t\t");
    printf("| |  | |    _   (_)                                   \n");  printf("\t\t\t\t\t\t");
    printf("| |  | |__ | |_  _ ____   ____                        \n");  printf("\t\t\t\t\t\t");
    printf(" \\ \\/ / _ \\|  _)| |  _ \\ / _  |                       \n"); printf("\t\t\t\t\t\t");
    printf("  \\  / |_| | |__| | | | ( ( | |                       \n"); printf("\t\t\t\t\t\t");
    printf("   \\/ \\___/ \\___)_|_| |_|\\_|| |                       \n");printf("\t\t\t\t\t\t");
    printf("                        (_____|                       \n");printf("\t\t\t\t\t");
	 printf(" ____            _     _                         _ \n");printf("\t\t\t\t\t"); 
    printf("|  _ \\  __ _ ___| |__ | |__   ___   __ _ _ __ __| |\n");printf("\t\t\t\t\t"); 
    printf("| | | |/ _` / __| '_ \\| '_ \\ / _ \\ / _` | '__/ _` |\n");printf("\t\t\t\t\t"); 
    printf("| |_| | (_| \\__ \\ | | | |_) | (_) | (_| | | | (_| |\n");printf("\t\t\t\t\t"); 
    printf("|____/ \\__,_|___/_| |_|_.__/ \\___/ \\__,_|_|  \\__,_|\n");printf("\n\t\t\t\t\t"); 
	
printf("===================================================");
printf("\n\t\t\t\t\t\t");  print_voting_position("config.csv");
printf("\t\t\t\t\t      ======================================\n");
//}
    printf("\t\t\t\t\t   Remaining time (hours:min): %02d:%02d\n", remaining_hours, remaining_minutes);
}

// Load candidates from config.csv
int load_candidates(char candidate_names[][50]) {
    FILE *config_file = fopen("config.csv", "r");
    if (config_file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to open config file.\n");
        return 0;
    }

    char line[256];
    fgets(line, sizeof(line), config_file);
    fgets(line, sizeof(line), config_file);

    char *candidates = strtok(line, ",");
    candidates = strtok(NULL, ",");
    candidates = strtok(NULL, ",");

    int num_candidates = 0;
    char *token = strtok(candidates, ";");
    while (token != NULL && num_candidates < MAX_CANDIDATES) {
        strcpy(candidate_names[num_candidates++], trim(token));
        token = strtok(NULL, ";");
    }

    fclose(config_file);
    return num_candidates;
}

// Count IDs in copy_of_candidates.csv
int count_ids() {
    FILE *file = fopen("results/copy_of_candidates.csv", "r");
    if (file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to find 'results/copy_of_candidates.csv'.\n");
        return 0;
    }

    char line[256];
    int id_count = 0;

    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) != NULL) {
        id_count++;
    }

    fclose(file);
    return id_count;
}

// Validate user login
int validate_user(const char *username, const char *password1) {
    FILE *file = fopen("results/copy_of_candidates.csv", "r");
    if (file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to open candidates file in results folder.\n");
        return 0;
    }

    char line[256];
    char file_username[50], file_password[50], vote_status[20], selection_status[20];
    int found = 0;

    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%[^,],%*[^,],%[^,],%[^,],%[^\n]", file_username, file_password, vote_status, selection_status);
        trim(file_username);
        trim(file_password);

        if (strcmp(file_username, username) == 0 && strcmp(file_password, password1) == 0) {
            if (strcmp(vote_status, "NOT VOTED") == 0 && strcmp(selection_status, "Not Selected") == 0) {
                found = 1;
                break;
            } else {
                printf("\t\t\t\t\t   You have already voted or are not eligible.\n");
                fclose(file);
                sleep(3);
                founder=0;
                display_main_menu();
            }
        }
    }

    fclose(file);
    return found;
}

// Record vote
void record_vote(const char *username, const char *candidate_name) {
    FILE *file = fopen("results/copy_of_candidates.csv", "r+");
    if (file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to open candidates file in results folder.\n");
        return;
    }

    FILE *temp_file = fopen("results/temp_file.csv", "w");
    if (temp_file == NULL) {
        printf("\t\t\t\t\t   Error: Unable to open temporary file for writing.\n");
        fclose(file);
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char file_username[50], extra_data[100], file_password[50], vote_status[20], selection_status[50];
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,]", file_username, extra_data, file_password, vote_status, selection_status);

        if (strcmp(file_username, username) == 0) {
            fprintf(temp_file, "%s,%s,%s,Selected,%s\n", file_username, extra_data, file_password, candidate_name);
            printf("\t\t\t\t\t   Vote recorded successfully for %s.\n", candidate_name);
            found = 1;
        } else {
            fprintf(temp_file, "%s,%s,%s,%s,%s\n", file_username, extra_data, file_password, vote_status, selection_status);
        }
    }

    if (!found) {
        printf("\t\t\t\t\t   Error: User ID not found in candidates file.\n");
    }

    fclose(file);
    fclose(temp_file);

    if (remove("results/copy_of_candidates.csv") == 0) {
        if (rename("results/temp_file.csv", "results/copy_of_candidates.csv") == 0) {
            printf("\t\t\t\t\t   File updated successfully.\n");
        } else {
            printf("\t\t\t\t\t   Error renaming the temporary file.\n");
        }
    } else {
        printf("\t\t\t\t\t   Error removing the original file.\n");
    }
}

// Voting function
void vote_in_election(time_t start_time, int allowed_hours, int allowed_minutes) {
    char candidate_names[MAX_CANDIDATES][50];
    int num_candidates = load_candidates(candidate_names);
    if (num_candidates == 0) {
        printf("\t\t\t\t\t   Error: No candidates found.\n");
        return;
    }

    int id_count = count_ids();
    if (id_count == 0) {
        printf("\t\t\t\t\t   Error: No users found.\n");
        return;
    }
    char username[50], password1[50];
    printf("\t\t\t\t\t   Login your Account :\n");
    printf("\t\t\t\t\t   Enter ID / CNIC : ");
    scanf("%s", username);
    printf("\t\t\t\t\t   Enter Password : ");
    scanf("%s", password1);
	
	
	printf("\t\t\t\t\t   Please wait a sec ");
	sleep(3);
	founder=0;
    update_remaining_time(start_time, allowed_hours, allowed_minutes);

    if (validate_user(username, password1)) {
        printf("\t\t\t\t\t   Choose your candidate:\n");
        for (int i = 0; i < num_candidates; i++) {
            printf("%d. %s\n", i + 1, candidate_names[i]);
        }
        int choice;
        printf("\t\t\t\t\t   Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= num_candidates) {
            record_vote(username, candidate_names[choice - 1]);
        } else {
            printf("\t\t\t\t\t   Invalid choice. Vote not recorded.\n");
            sleep(4);
        }
    } else {
        printf("\t\t\t\t\t   Invalid login or not eligible to vote.\n");
        sleep(5);
    }
}

void main_login_voters() {
    int allowed_hours, allowed_minutes;
    if (!load_voting_duration(&allowed_hours, &allowed_minutes)) {
        printf("\t\t\t\t\t   Error loading voting duration from config.\n");
        return;
    }

    time_t start_time = time(NULL);
    initialize_time_log(allowed_hours, allowed_minutes);

    while (1) {
        update_remaining_time(start_time, allowed_hours, allowed_minutes);
        vote_in_election(start_time, allowed_hours, allowed_minutes);
    }
}
///Result----> previsous result and result creation

int main_result() {
    int choice;
    do {
        system("cls");
        display_admin_menu();
        printf("\n\t\t\t\t\t   1. Create Voting Result\n");
        printf("\t\t\t\t\t   2. See Results\n");
        printf("\t\t\t\t\t   3. Exit\n");
        printf("\t\t\t\t\t   Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\t\t\t\t\t   Invalid choice. Try again.\n");
            while (getchar() != '\n'); 
            sleep(2);
            continue; 
        }

        switch (choice) {
            case 1:
                create_voting_result();
                break;
            case 2:
                see_results();
                break;
            case 3:
                sleep(2);
                menu_call();
                break;
            default:
                printf("\t\t\t\t\t   Invalid choice. Try again.\n");
                sleep(2);
                break;
        }
    } while (choice != 3);

    return 0;
}


// Function definitions
void create_voting_result() {
    FILE *configFile = fopen("config.csv", "r");
    FILE *candidatesFile = fopen("results/copy_of_candidates.csv", "r");
    char line[1024], *token, candidates[MAX_CANDIDATES][MAX_NAME_LEN];
    int votes[MAX_CANDIDATES] = {0}, candidateCount = 0;
    char position[50] = "";
    char identifier[50], resultFileName[100];

    if (!configFile || !candidatesFile) {
        printf("\t\t\t\t\t   Error: Cannot open required files.\n");
        return;
    }

    // Prompt admin for the file identifier (e.g., "President")
    printf("\t\t\t\t\t   Enter identifier for result file (e.g. CR'): ");
    scanf("%49s", identifier);
    snprintf(resultFileName, sizeof(resultFileName), "%s%s.csv", RESULT_PREFIX, identifier);

    // Read candidate names and position from config.csv
    fgets(line, sizeof(line), configFile); // Skip header
    if (fgets(line, sizeof(line), configFile)) {
        token = strtok(line, ",");
        strcpy(position, token); // POSITION column
        token = strtok(NULL, ","); // NUMBER OF CANDIDATE column
        token = strtok(NULL, ","); // CANDIDATES NAMES column

        char *name = strtok(token, ";");
        while (name && candidateCount < MAX_CANDIDATES) {
            strcpy(candidates[candidateCount++], name);
            name = strtok(NULL, ";");
        }
    }
    fclose(configFile);

    // Process votes from copy_of_candidates.csv
    fgets(line, sizeof(line), candidatesFile); // Skip header
    while (fgets(line, sizeof(line), candidatesFile)) {
        token = strtok(line, ",");
        for (int i = 0; i < 4; i++) token = strtok(NULL, ","); // Move to "CANDIDATE SELECTED" column

        if (!token || strstr(token, "Not Selected")) continue;

        char candidateName[MAX_NAME_LEN];
        strncpy(candidateName, token, strcspn(token, " "));
        candidateName[strcspn(token, " ")] = '\0';

        for (int i = 0; i < candidateCount; i++) {
            if (strcasecmp(candidates[i], candidateName) == 0) {
                votes[i]++;
                break;
            }
        }
    }
    fclose(candidatesFile);

    // Determine winner
    int maxVotes = 0, winnerIndex = -1;
    for (int i = 0; i < candidateCount; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    // Write results with aligned columns and headers
    FILE *resultFile = fopen(resultFileName, "w");
    fprintf(resultFile, "Candidates Name      |   Voters Quantity\n");
    fprintf(resultFile, "---------------------|------------------\n");
    for (int i = 0; i < candidateCount; i++) {
        fprintf(resultFile, "%-20s | %4d\n", candidates[i], votes[i]);
    }
    if (winnerIndex != -1) {
        fprintf(resultFile, "\nWinner   : %s\n", candidates[winnerIndex]);
    }
    fprintf(resultFile, "Position : %s\n", position);
    fclose(resultFile);

    printf("\t\t\t\t\t   Result file '%s' created successfully.\n", resultFileName);
	sleep(3);
    
}
void see_results() {
    DIR *dir = opendir(".");
    struct dirent *entry;
    FILE *resultFile;
    char line[1024], fileName[100];

    if (!dir) {
        printf("\t\t\t\t\t   Error: Cannot open directory.\n");
        return;
    }

    printf("\t\t\t\t\t   Available Results:\n");
    int fileCount = 0;
    char files[100][100];

    // List files starting with RESULT_PREFIX
    while ((entry = readdir(dir)) != NULL) {
        if (strncmp(entry->d_name, RESULT_PREFIX, strlen(RESULT_PREFIX)) == 0) {
            printf("\t\t\t\t\t   %d. %s\n", ++fileCount, entry->d_name);
            strcpy(files[fileCount - 1], entry->d_name);
        }
    }
    closedir(dir);

    if (fileCount == 0) {
        printf("\t\t\t\t\t   No result files available.\n");
        return;
    }

    int choice;
    printf("\t\t\t\t\t   Enter the file number to display: ");
    scanf("%d", &choice);
	sleep(2);
		display_admin_menu();
	
    if (choice < 1 || choice > fileCount) {
        printf("\t\t\t\t\t   Invalid choice.\n");
        return;
    }

    // Display selected result file
    resultFile = fopen(files[choice - 1], "r");
    if (resultFile) {
        printf("\n\t\t\t\t\t   File: %s\n", files[choice - 1]);
        printf("\t\t\t\t\t   ");printf("Candidates Name      |   Voters Quantity\n");
        fgets(line, sizeof(line), resultFile); // Skip header
        while (fgets(line, sizeof(line), resultFile)) {
        printf("\t\t\t\t\t   ");    printf("%s", line);
        }
        fclose(resultFile);
    }
    
    printf("\n\t\t\t\t\t   Enter any key to Exit.");
    
    sleep(4);
    fflush(stdin);
 	getchar();
}






///End



