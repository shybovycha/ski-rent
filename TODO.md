1) make not a template static methods, but static methods for a template class

QueryBuilder<T> {
		QStringList getAllFields();
		QString tableName();
		void delete(int id) {
		     return QString("DELETE FROM %1 WHERE id = %2").arg(tableName()).arg(id);
		}

		void update(T newEntity) {
		     return QString("UPDATE %1 SET %2 WHERE id = %3").arg(tableName()).arg(getAllFields().map(wrapForUpdate(newEntity))).arg(newEntity.getId());
		}

protected:
		QString wrapForUpdate(T newEntity, QString src) {
			return QString("`%1` = '%2'").arg(src).arg(newEntity.get(src));
		}
}

2) make even not static methods for a template class, but methods for a template class' instance