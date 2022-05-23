#pragma once
struct Person {
	String name;
	String address;
	String phone;

	Person(String name, String address, String phone)
		:name(name), address(address), phone(phone) {}
};
