show_help () {
    echo "Usage: ./bdsh [OPTION]... [COMMAND] [REQUEST]
OPTION:
  -h				display usage
  -f FILE			json database file
  -j                json formated output for select command

COMMAND and REQUEST:
	create		create database
			Exemple: 
				./bdsh -f file.json create database
				./bdsh -f file.json create table user id,firstname,lastname
				./bdsh -f file.json create table age id,age

	insert		insert data in database
			Exemple:
				./bdsh -f file.json insert user id=1,firstname=John,lastname=SMITH
				./bdsh -f file.json insert user id=4,firstname=Robert\ John,lastname=WILLIAMS
				./bdsh -f file.json insert user id=2,firstname=Lisa,lastname=SIMPSON
				./bdsh -f file.json insert user id=10,lastname=SMITH
				./bdsh -f file.json insert user firstname=Laura,lastname=SMITH
				./bdsh -f file.json insert user id=9
				./bdsh -f file.json insert age id=1,age=42

	describe      describe table structure
			Exemple:
				./bdsh -f file.json describe user
				id
				firstname
				lastname

	select		display data from database
			Exemple:
				./bdsh -f file.json select user firstname,lastname
				firstname    | lastname
				-------------------------
				John         | SMITH
				Robert John  | WILLIAMS
				Lisa         | SIMPSON
				             | SMITH
				Laura        | SMITH
				             |
				./bdsh -f file.json select user lastname,firstname order
				lastname  | firstname
				-------------------------
				          |
				SIMPSON   | Lisa
				SMITH     |
				SMITH     | John
				SMITH     | Laura
				WILLIAMS  | Robert John"
    exit 0;
}

arguments_error () {
    echo "Syntax error in command line: $1" >&2;
    exit 1;
}


invalid_flag_error () {
    echo -e "This is not a valid flag: $1 \nConsult -h for help" >&2;
    exit 1;
}

file_path_not_found_error () {
    echo "No path for database file supplied $1." >&2;
    exit 1;
}

file_already_exists_error () {
    echo "File $1 already exists." >&2;
    exit 1;
}

table_already_exists_error () {
    echo "Table $1 already exists." >&2;
    exit 84;
}

table_not_found_error () {
	echo -e "Table \"$1\" does not exist." >&2;
	exit 1;
}

file_not_found_error () {
	echo -e "File \"$1\" does not exist." >&2;
	exit 1;
}

field_not_found_error () {
	echo -e "Field \"$1\" does not exist." >&2;
	exit 1;
}