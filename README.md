# Address-Book-C
# Address Book Management System in C

A console-based application written in C to manage contact information such as names, phone numbers, and email addresses. The project features full CRUD operations (Create, Read, Update, Delete), multi-attribute searching, sorting, input validation, and CSV file persistence.

---

## 📌 Features

* **Add Contacts**: Add new contacts with automatic validation for names, phone numbers (10 digits), and emails (`@` and `.com` checks). Prevents duplicate phone numbers and emails.
* **Search Contacts**: Search for existing contacts by Name, Phone Number, or Email (case-insensitive search).
* **Edit Contacts**: Update existing contact details after selecting them from search results.
* **Delete Contacts**: Remove a contact from memory with user confirmation.
* **Sort & Display**: List all contacts sorted alphabetically by Name, Phone Number, or Email using Bubble Sort.
* **File Persistence**: Load saved contacts on startup from `contact.csv` and save updated records back to the CSV file upon exiting.
* **Dummy Data Auto-Load**: Includes a helper module to easily populate sample data for testing.

---

## 🛠️ File Structure

* `main.c` - Entry point containing the interactive menu loop.
* `contact.c` / `contact.h` - Core logic for adding, searching, editing, deleting, sorting, and validating contacts.
* `file.c` / `file.h` - CSV file handling for loading and saving data persistently.
* `populate.c` / `populate.h` - Module to pre-load sample contacts for quick testing.
* `contact.csv` - Data storage file.

---

## ⚙️ How to Compile and Run

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/YOUR_USERNAME/Address-Book-C.git](https://github.com/YOUR_USERNAME/Address-Book-C.git)
   cd Address-Book-C
