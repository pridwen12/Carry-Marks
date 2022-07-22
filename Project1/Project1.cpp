#include <iostream>
#include <string>
#include <fstream>	
#include <iomanip>

using namespace std;

class Assessment
{
public:
	string type;
	float mark;
	Assessment* next;

	Assessment()
	{
		type = " ";
		mark = 0;
		next = NULL;
	}
};

class Student
{
public:
	string ID;
	float cmark;
	Assessment* head;

	Student()
	{
		ID = " ";
		cmark = 0;
		head = NULL;
	}

	void push(Assessment** head_ref, string new_type, float new_mark)
	{
		Assessment* new_assessment = new Assessment();
		new_assessment->type = new_type;
		new_assessment->mark = new_mark;
		new_assessment->next = (*head_ref);
		(*head_ref) = new_assessment;
	}

	void initialise()
	{
		push(&head, "Lab Exe", 0);
		push(&head, "MD Test", 0);
		push(&head, "Assignment", 0);
		push(&head, "Quiz", 0);
	}

	void append(Assessment* assessment, string a, float b)
	{
		while (assessment->type != a)
		{
			assessment = assessment->next;
		}

		assessment->mark = b;
	}

	int validate(Assessment* assessment, string a)
	{
		while (assessment->type != a)
		{
			assessment = assessment->next;
		}

		if (assessment->mark == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	void display(Assessment* assessment, string a)
	{
		while (assessment->type != a)
		{
			assessment = assessment->next;
		}
		cout << assessment->mark << "%";
	}

	float file(Assessment* assessment, string a)
	{
		while (assessment->type != a)
		{
			assessment = assessment->next;
		}

		return assessment->mark;
	}

	void calculate(Assessment* assessment)
	{
		float carry = 0;

		while (assessment != NULL)
		{
			carry = carry + assessment->mark;
			assessment = assessment->next;
		}
		cout << carry << "%" << endl;
	}

	float carry(Assessment* assessment)
	{
		float carry = 0;

		while (assessment != NULL)
		{
			carry = carry + assessment->mark;
			assessment = assessment->next;
		}
		return carry;
	}

};

class List
{
public:
	int index;
	Student record[100];
};

int menu()
{
	int choice = 0;

	cout << "CARRY MARK PROGRAM " << endl;
	cout << "1. Add New Student " << endl;
	cout << "2. Update Assessment " << endl;
	cout << "3. Carry Mark Summary " << endl;
	cout << "4. Carry Mark Summary (Save to File) " << endl;
	cout << "5. Exit " << endl;
	cout << "Select Menu: ";
	cin >> choice;
	cout << endl;

	return choice;
}

int main()
{
	List stat;
	int choice = 0, i = 0, option = 0, val = 0, y = 0, z = 0;
	string input, file_name;
	float mark = 0, placeholder = 0;
	char repeat = 'y';

	do
	{
		choice = menu();

		stat.record[i].initialise();

		switch (choice)
		{
		case 1:
		{
			cout << "Enter Student ID: ";
			cin >> input;

			z = 0;

			for (y = 0; y < 100; y++)
			{
				if (input == stat.record[y].ID)
				{
					cout << "Student ID is already in use" << endl;
					z = 1;
					break;
				}
			}

			if (z == 1)
			{
				cout << endl;
				break;
			}

			stat.record[i].ID = input;

			do {
				cout << "Assessment Menu: " << endl;
				cout << "1. Quiz " << endl;
				cout << "2. Assignment " << endl;
				cout << "3. Mid Term Test " << endl;
				cout << "4. Lab Exercise " << endl;
				cout << "Select option: ";
				cin >> option;
				switch (option)
				{
				case 1:
					val = stat.record[i].validate(stat.record[i].head, "Quiz");
					if (val == 0)
					{
						cout << "Enter Quiz mark (40): ";
						cin >> mark;
						while (mark <= 0 || mark > 40)
						{
							cout << "Invalid mark, please enter again." << endl;
							cout << "Enter Quiz mark (40): ";
							cin >> mark;
						}
						cout << "Percentage of Quiz is " << mark / 40 * 15 << "%" << endl;
						stat.record[i].append(stat.record[i].head, "Quiz", mark / 40 * 15);
					}
					else
					{
						cout << "Quiz mark already exists. " << endl;
						cout << "Choose UPDATE option in MAIN MENU to update. " << endl;
					}
					break;
				case 2:
					val = stat.record[i].validate(stat.record[i].head, "Assignment");
					if (val == 0)
					{
						cout << "Enter Assignment mark (10): ";
						cin >> mark;
						while (mark <= 0 || mark > 10)
						{
							cout << "Invalid mark, please enter again." << endl;
							cout << "Enter Assignment mark (10): ";
							cin >> mark;
						}
						cout << "Percentage of Assignment is " << mark / 10 * 10 << "%" << endl;
						stat.record[i].append(stat.record[i].head, "Assignment", mark / 10 * 10);
					}
					else
					{
						cout << "Assignment mark already exists. " << endl;
						cout << "Choose UPDATE option in MAIN MENU to update. " << endl;
					}
					break;
				case 3:
					val = stat.record[i].validate(stat.record[i].head, "MD Test");
					if (val == 0)
					{
						cout << "Enter Mid Term Test mark (50): ";
						cin >> mark;
						while (mark <= 0 || mark > 50)
						{
							cout << "Invalid mark, please enter again." << endl;
							cout << "Enter Mid Term Test mark (50): ";
							cin >> mark;
						}
						cout << "Percentage of Mid Term Test is " << mark / 50 * 20 << "%" << endl;
						stat.record[i].append(stat.record[i].head, "MD Test", mark / 50 * 20);
					}
					else
					{
						cout << "Mid Term Test mark already exists. " << endl;
						cout << "Choose UPDATE option in MAIN MENU to update. " << endl;
					}
					break;
				case 4:
					val = stat.record[i].validate(stat.record[i].head, "Lab Exe");
					if (val == 0)
					{
						cout << "Enter Lab Exercise mark (15): ";
						cin >> mark;
						while (mark <= 0 || mark > 15)
						{
							cout << "Invalid mark, please enter again." << endl;
							cout << "Enter Lab Exercise mark (15): ";
							cin >> mark;
						}
						cout << "Percentage of Lab Exercise is " << mark / 15 * 15 << "%" << endl;
						stat.record[i].append(stat.record[i].head, "Lab Exe", mark / 15 * 15);
					}
					else
					{
						cout << "Lab Exercise mark already exists. " << endl;
						cout << "Choose UPDATE option in MAIN MENU to update. " << endl;
					}
					break;
				}

				cout << "Add another assessment [Y/N]: ";
				cin >> repeat;
				cout << endl;
				stat.record[i].cmark = stat.record[i].carry(stat.record[i].head);
			} while (repeat == 'y' || repeat == 'Y');
			break;
		}
		case 2:
			cout << "Enter Student ID: ";
			cin >> input;

			for (y = 0; y < 100; y++)
			{
				if (input == stat.record[y].ID)
				{
					do
					{
						cout << "Assessment Menu: " << endl;
						cout << "1. Quiz " << endl;
						cout << "2. Assignment " << endl;
						cout << "3. Mid Term Test " << endl;
						cout << "4. Lab Exercise " << endl;
						cout << "Select option: ";
						cin >> option;

						switch (option)
						{
						case 1:
							cout << "Current Percentage of Quiz: ";
							stat.record[y].display(stat.record[y].head, "Quiz");
							cout << endl;
							cout << "Enter new Quiz mark (40): ";
							cin >> mark;
							while (mark <= 0 || mark > 40)
							{
								cout << "Invalid mark, please enter again." << endl;
								cout << "Enter Quiz mark (40): ";
								cin >> mark;
							}
							cout << "New Percentage of Quiz is " << mark / 40 * 15 << "%" << endl;
							stat.record[y].append(stat.record[y].head, "Quiz", mark / 40 * 15);
							break;
						case 2:
							cout << "Current Percentage of Assignment: ";
							stat.record[y].display(stat.record[y].head, "Assignment");
							cout << endl;
							cout << "Enter new Assignment mark (10): ";
							cin >> mark;
							while (mark <= 0 || mark > 10)
							{
								cout << "Invalid mark, please enter again." << endl;
								cout << "Enter Assignment mark (10): ";
								cin >> mark;
							}
							cout << "New Percentage of Assignment is " << mark / 10 * 10 << "%" << endl;
							stat.record[y].append(stat.record[y].head, "Assignment", mark / 10 * 10);
							break;
						case 3:
							cout << "Current Percentage of Mid Term Test: ";
							stat.record[y].display(stat.record[y].head, "MD Test");
							cout << endl;
							cout << "Enter new Mid Term Test mark (50): ";
							cin >> mark;
							while (mark <= 0 || mark > 50)
							{
								cout << "Invalid mark, please enter again." << endl;
								cout << "Enter Mid Term Test mark (50): ";
								cin >> mark;
							}
							cout << "New Percentage of Mid Term Test is " << mark / 50 * 20 << "%" << endl;
							stat.record[y].append(stat.record[y].head, "MD Test", mark / 50 * 20);
							break;
						case 4:
							cout << "Current Percentage of Lab Exercise: ";
							stat.record[y].display(stat.record[y].head, "Lab Exe");
							cout << endl;
							cout << "Enter new Lab Exercise mark (15): ";
							cin >> mark;
							while (mark <= 0 || mark > 15)
							{
								cout << "Invalid mark, please enter again." << endl;
								cout << "Enter Lab Exercise mark (15): ";
								cin >> mark;
							}
							cout << "New Percentage of Lab Exercise is " << mark / 15 * 15 << "%" << endl;
							stat.record[y].append(stat.record[y].head, "Lab Exe", mark / 15 * 15);
							break;
						}
						cout << "Update another assessment [Y/N]: ";
						cin >> repeat;
						cout << endl;
						stat.record[y].cmark = stat.record[y].carry(stat.record[y].head);
					} while (repeat == 'y' || repeat == 'Y');
				}
			}
			break;

		case 3:
			cout << "Display Menu: " << endl;
			cout << "1. Individual " << endl;
			cout << "2. All " << endl;
			cout << "3. Highest carry mark " << endl;
			cout << "Select option: ";
			cin >> option;
			cout << endl;

			switch (option)
			{
			case 1:
				cout << "Enter Student ID: ";
				cin >> input;
				for (y = 0; y < 100; y++)
				{
					if (input == stat.record[y].ID)
					{

						cout << "::Carry Mark Details::" << endl;
						cout << "Student ID: " << input << endl;
						cout << "Quiz: ";
						stat.record[y].display(stat.record[y].head, "Quiz");
						cout << endl;
						cout << "Assignment: ";
						stat.record[y].display(stat.record[y].head, "Assignment");
						cout << endl;
						cout << "Mid Term Test: ";
						stat.record[y].display(stat.record[y].head, "MD Test");
						cout << endl;
						cout << "Lab Exercise: ";
						stat.record[y].display(stat.record[y].head, "Lab Exe");
						cout << endl;
						cout << "Total Carry Mark: ";
						stat.record[y].calculate(stat.record[y].head);

						cout << endl;
						cout << "End of Summary" << endl;
						z = 1;
						break;
					}
				}

				if (z == 1)
				{
					cout << endl;
					break;
				}
				break;
			case 2:
				for (y = 0; y < 100; y++)
				{
					if (stat.record[y].ID != " ")
					{
						cout << "::Carry Mark Details::" << endl;
						cout << "Student ID: " << stat.record[y].ID << endl;
						cout << "Quiz: ";
						stat.record[y].display(stat.record[y].head, "Quiz");
						cout << endl;
						cout << "Assignment: ";
						stat.record[y].display(stat.record[y].head, "Assignment");
						cout << endl;
						cout << "Mid Term Test: ";
						stat.record[y].display(stat.record[y].head, "MD Test");
						cout << endl;
						cout << "Lab Exercise: ";
						stat.record[y].display(stat.record[y].head, "Lab Exe");
						cout << endl;
						cout << "Total Carry Mark: ";
						stat.record[y].calculate(stat.record[y].head);

						cout << endl;
						cout << "End of Summary" << endl;
					}

				}
				break;
			case 3:
				for (y = 0; y < 100; y++)
				{
					if (placeholder < stat.record[y].cmark)
					{
						placeholder = stat.record[y].cmark;
					}
				}

				for (y = 0; y < 100; y++)
				{
					if (placeholder == stat.record[y].cmark)
					{

						cout << "::Carry Mark Details::" << endl;
						cout << "Student ID: " << stat.record[y].ID << endl;
						cout << "Quiz: ";
						stat.record[y].display(stat.record[y].head, "Quiz");
						cout << endl;
						cout << "Assignment: ";
						stat.record[y].display(stat.record[y].head, "Assignment");
						cout << endl;
						cout << "Mid Term Test: ";
						stat.record[y].display(stat.record[y].head, "MD Test");
						cout << endl;
						cout << "Lab Exercise: ";
						stat.record[y].display(stat.record[y].head, "Lab Exe");
						cout << endl;
						cout << "Total Carry Mark: ";
						stat.record[y].calculate(stat.record[y].head);

						cout << endl;
						z = 1;
						break;
					}
				}
				cout << "End of Summary" << endl;

				if (z == 1)
				{
					cout << endl;
					break;
				}

				break;
			}
			break;

		case 4:
		{
			cout << "Enter file name: ";
			cin >> file_name;
			ofstream out(file_name + ".txt");
			out << "STUDENT ID NO" << left << setw(5) << " " << "QUIZ" << left << setw(5) << " " << "ASSIGNMENT" << left << setw(5) << " " << "MD TEST" << left << setw(5) << " " << "LAB EXE" << left << setw(5) << " " << "TOTAL CM" << endl;
			for (y = 0; y < 100; y++)
			{
				if (stat.record[y].ID != " ")
				{
					out << stat.record[y].ID << left << setw(10) << " " << stat.record[y].file(stat.record[y].head, "Quiz");
					out << left << setw(10) << " " << stat.record[y].file(stat.record[y].head, "Assignment");
					out << left << setw(10) << " " << stat.record[y].file(stat.record[y].head, "MD Test");
					out << left << setw(10) << " " << stat.record[y].file(stat.record[y].head, "Lab Exe");
					out << left << setw(10) << " " << stat.record[y].cmark << endl;
				}

			}
			out.close();
			cout << "File " + file_name + ".txt is saved." << endl << endl;
			break;
		}

		case 5:
			return 0;
		}

		i++;
	} while (true);

	return 0;
}