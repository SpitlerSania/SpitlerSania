#define _CRT_SECURE_NO_WARNINGS

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

	class Priority_queuee_interface
	{
	public:

		virtual void push(
			char const*,
			unsigned int const) {}

		virtual char const* get_top_value() const { return nullptr; }

		virtual void pop() {}

		virtual Priority_queuee_interface* merge(
			Priority_queuee_interface*) {
			return nullptr;
		}
	};

#endif