#include <iostream>
#include <fstream>
#include <string>
#include "DB.hh"
#include "Table.hh"
#include "Pattern.hh"
#include "Type.hh"

#include "hardcoded.hh" //192.168.113.98

bool Table::upper = false;
bool DB::upper = false;

int main(void) {
	DB db("exam");

	Table article("Article_1");
	article.field("visible", boolean_(), visible_);
	article.field("password", string_(), password_);
	article.field("published_on", date_(), published_on_);

	Table category("Category");
	category.field("priority", double_(), priority_double_);
	category.field("created_by", string_(), created_by_);

	Table user("User");
	user.field("age", integer_(), age_);
	user.field("name",varchar_(), name_);
	user.field("income", float_(), income_);

	Table tag("Tag");
	tag.field("description", varchar_(), description_);
	tag.field("name", varchar_(), name_);

	Table category_tag;
	db.many_to_many(&category, &tag, &category_tag);
	db.one_to_many(&tag, &user);
	db.one_to_one(&user, &article);

	db.add_if_missing(&article);
	db.add_if_missing(&category);
	db.add_if_missing(&user);
	db.add_if_missing(&tag);

	std::ofstream creates("creates.sql", std::ios::out);
	creates << db.create();

	std::ofstream inserts("inserts.sql", std::ios::out);
	inserts << db.use() << db.insert(7);

	std::ofstream selects1("selects1.sql", std::ios::out);
	selects1 << db.use() << db.select(&user, &category, JoinType::inner, 3);

	std::ofstream migrates("migrates.sql", std::ios::out);
	Table migrate("Tag_part1");
	std::vector<std::string> fields;
	fields.push_back(std::string("name"));
	migrates << db.use();
	migrates << db.migrate(&migrate, fields, &tag, std::string("Tag_part2"));

	std::ofstream selects2("selects2.sql", std::ios::out);
	selects2 << db.use() << db.select(&article, &tag, JoinType::inner, 2);

	return 0;
}
