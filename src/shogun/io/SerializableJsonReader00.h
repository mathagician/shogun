/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Soeren Sonnenburg, Yuyu Zhang
 */
#ifndef __SERIALIZABLE_JSON_READER_00_H__
#define __SERIALIZABLE_JSON_READER_00_H__

#include <shogun/lib/config.h>

#ifdef HAVE_JSON

#include <shogun/io/SerializableJsonFile.h>

namespace shogun
{
#define IGNORE_IN_CLASSLIST
IGNORE_IN_CLASSLIST class SerializableJsonReader00
	:public CSerializableFile::TSerializableReader {
	CSerializableJsonFile* m_file;

public:
	explicit SerializableJsonReader00(CSerializableJsonFile* file);
	virtual ~SerializableJsonReader00();

	/** @return object name */
	virtual const char* get_name() const {
		return "SerializableJsonReader00";
	}

	virtual bool read_scalar_wrapped(
		const TSGDataType* type, void* param);

	virtual bool read_cont_begin_wrapped(
		const TSGDataType* type, index_t* len_read_y,
		index_t* len_read_x);
	virtual bool read_cont_end_wrapped(
		const TSGDataType* type, index_t len_read_y,
		index_t len_read_x);

	virtual bool read_string_begin_wrapped(
		const TSGDataType* type, index_t* length);
	virtual bool read_string_end_wrapped(
		const TSGDataType* type, index_t length);

	virtual bool read_stringentry_begin_wrapped(
		const TSGDataType* type, index_t y);
	virtual bool read_stringentry_end_wrapped(
		const TSGDataType* type, index_t y);

	virtual bool read_sparse_begin_wrapped(
		const TSGDataType* type, index_t* length);
	virtual bool read_sparse_end_wrapped(
		const TSGDataType* type, index_t length);

	virtual bool read_sparseentry_begin_wrapped(
		const TSGDataType* type, SGSparseVectorEntry<char>* first_entry,
		index_t* feat_index, index_t y);
	virtual bool read_sparseentry_end_wrapped(
		const TSGDataType* type, SGSparseVectorEntry<char>* first_entry,
		index_t* feat_index, index_t y);

	virtual bool read_item_begin_wrapped(
		const TSGDataType* type, index_t y, index_t x);
	virtual bool read_item_end_wrapped(
		const TSGDataType* type, index_t y, index_t x);

	virtual bool read_sgserializable_begin_wrapped(
		const TSGDataType* type, char* sgserializable_name,
		EPrimitiveType* generic);
	virtual bool read_sgserializable_end_wrapped(
		const TSGDataType* type, const char* sgserializable_name,
		EPrimitiveType generic);

	virtual bool read_type_begin_wrapped(
		const TSGDataType* type, const char* name,
		const char* prefix);
	virtual bool read_type_end_wrapped(
		const TSGDataType* type, const char* name,
		const char* prefix);
};
}

#endif /* HAVE_JSON  */
#endif /* __SERIALIZABLE_JSON_READER_00_H__  */
