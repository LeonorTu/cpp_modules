#include "Serializer.hpp"

int main(void)
{
	Data data = {42};

	std::cout << "Original Data object address: " << &data << std::endl;
	std::cout << "Original Data value: " << data.value << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized (uintptr_t) value: " << raw << std::endl;

	Data* deserializedPtr = Serializer::deserialize(raw);

	std::cout << "Deserialized Data object address: " << deserializedPtr << std::endl;
	std::cout << "Deserialized Data value: " << deserializedPtr->value << std::endl;

	if (deserializedPtr == &data)
		std::cout << "The deserialized pointer correctly points to the original Data object." << std::endl;
	else
		std::cout << "The deserialized pointer does NOT point to the original Data object." << std::endl;
}