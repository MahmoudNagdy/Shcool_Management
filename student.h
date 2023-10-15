void start_system();

struct student student_scan(void);

struct student student_scanName(struct student *arr, int index);

struct student student_scanID(struct student *arr, int index);

struct student student_scanAge(struct student *arr, int index);

struct student student_scanPhone(struct student *arr, int index);

void student_printAll(struct student *arr, int size);

void edit_ItemName(struct student *arr, int index);

void edit_ItemID(struct student *arr, int index);

void edit_ItemAge(struct student *arr, int index);

void edit_ItemPhone(struct student *arr, int index);

void print_student(struct student *arr,int ID, int size);

void student_call(struct student *arr,int ID, int size);

void delete_item(struct student *arr, int *size, int studentID);

int student_checkExist(struct student *arr, int ID, int size);