// -*- C++ -*-
//=============================================================================
/**
 *      Copyright (c) 2013,2014,2015 Guan Lisheng (guanlisheng@gmail.com)
 *
 *      @file
 *
 *      @author [sqlite2cpp.py]
 *
 *      @brief
 *
 *      Revision History:
 *          AUTO GENERATED at 2015-01-25 22:51:53.997000.
 *          DO NOT EDIT!
 */
//=============================================================================

#ifndef DB_TABLE_TRANSFERTRANS_V1_H
#define DB_TABLE_TRANSFERTRANS_V1_H

#include "DB_Table.h"

struct DB_Table_TRANSFERTRANS_V1 : public DB_Table
{
    struct Data;
    typedef DB_Table_TRANSFERTRANS_V1 Self;
    /** A container to hold list of Data records for the table*/
    struct Data_Set : public std::vector<Self::Data>
    {
        std::wstring to_json() const
        {
            json::Array a;
            for (const auto & item: *this)
            {
                json::Object o;
                item.to_json(o);
                a.Insert(o);
            }
            std::wstringstream ss;
            json::Writer::Write(a, ss);
            return ss.str();
        }
    };
    /** A container to hold a list of Data record pointers for the table in memory*/
    typedef std::vector<Self::Data*> Cache;
    typedef std::map<int, Self::Data*> Index_By_Id;
    Cache cache_;
    Index_By_Id index_by_id_;

    /** Destructor: clears any data records stored in memory */
    ~DB_Table_TRANSFERTRANS_V1() 
    {
        destroy_cache();
    }
	 
    /** Removes all records stored in memory (cache) for the table*/ 
    void destroy_cache()
    {
        std::for_each(cache_.begin(), cache_.end(), std::mem_fun(&Data::destroy));
        cache_.clear();
        index_by_id_.clear(); // no memory release since it just stores pointer and the according objects are in cache
    }

    /** Creates the database table if the table does not exist*/
    bool ensure(wxSQLite3Database* db)
    {
        if (!exists(db))
		{
			try
			{
				db->ExecuteUpdate("CREATE TABLE TRANSFERTRANS_V1 (ID INTEGER NOT NULL PRIMARY KEY, TABLETYPE TEXT NOT NULL UNIQUE, ID_TABLERECORD INTEGER NOT NULL, ID_CHECKINGACCOUNT INTEGER NOT NULL, TRANSFER INTEGER NOT NULL, ID_CURRENCY INTEGER NOT NULL)");
			}
			catch(const wxSQLite3Exception &e) 
			{ 
				wxLogError("TRANSFERTRANS_V1: Exception %s", e.GetMessage().c_str());
				return false;
			}
		}

        this->ensure_index(db);

        return true;
    }

    bool ensure_index(wxSQLite3Database* db)
    {
        try
        {
            db->ExecuteUpdate("CREATE INDEX IF NOT EXISTS IDX_ID_CHECKINGACCOUNT ON TRANSFERTRANS_V1 (ID_CHECKINGACCOUNT)");
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("TRANSFERTRANS_V1: Exception %s", e.GetMessage().c_str());
            return false;
        }

        return true;
    }

    struct ID : public DB_Column<int>
    { 
        static wxString name() { return "ID"; } 
        explicit ID(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    struct TABLETYPE : public DB_Column<wxString>
    { 
        static wxString name() { return "TABLETYPE"; } 
        explicit TABLETYPE(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct ID_TABLERECORD : public DB_Column<int>
    { 
        static wxString name() { return "ID_TABLERECORD"; } 
        explicit ID_TABLERECORD(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    struct ID_CHECKINGACCOUNT : public DB_Column<int>
    { 
        static wxString name() { return "ID_CHECKINGACCOUNT"; } 
        explicit ID_CHECKINGACCOUNT(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    struct TRANSFER : public DB_Column<int>
    { 
        static wxString name() { return "TRANSFER"; } 
        explicit TRANSFER(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    struct ID_CURRENCY : public DB_Column<int>
    { 
        static wxString name() { return "ID_CURRENCY"; } 
        explicit ID_CURRENCY(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    typedef ID PRIMARY;
    enum COLUMN
    {
        COL_ID = 0
        , COL_TABLETYPE = 1
        , COL_ID_TABLERECORD = 2
        , COL_ID_CHECKINGACCOUNT = 3
        , COL_TRANSFER = 4
        , COL_ID_CURRENCY = 5
    };

    /** Returns the column name as a string*/
    static wxString column_to_name(COLUMN col)
    {
        switch(col)
        {
            case COL_ID: return "ID";
            case COL_TABLETYPE: return "TABLETYPE";
            case COL_ID_TABLERECORD: return "ID_TABLERECORD";
            case COL_ID_CHECKINGACCOUNT: return "ID_CHECKINGACCOUNT";
            case COL_TRANSFER: return "TRANSFER";
            case COL_ID_CURRENCY: return "ID_CURRENCY";
            default: break;
        }
        
        return "UNKNOWN";
    }

    /** Returns the column number from the given column name*/
    static COLUMN name_to_column(const wxString& name)
    {
        if ("ID" == name) return COL_ID;
        else if ("TABLETYPE" == name) return COL_TABLETYPE;
        else if ("ID_TABLERECORD" == name) return COL_ID_TABLERECORD;
        else if ("ID_CHECKINGACCOUNT" == name) return COL_ID_CHECKINGACCOUNT;
        else if ("TRANSFER" == name) return COL_TRANSFER;
        else if ("ID_CURRENCY" == name) return COL_ID_CURRENCY;

        return COLUMN(-1);
    }
    
    /** Data is a single record in the database table*/
    struct Data
    {
        friend struct DB_Table_TRANSFERTRANS_V1;
        /** This is a instance pointer to itself in memory. */
        Self* view_;
    
        int ID;//  primary key
        wxString TABLETYPE;
        int ID_TABLERECORD;
        int ID_CHECKINGACCOUNT;
        int TRANSFER;
        int ID_CURRENCY;
        int id() const { return ID; }
        void id(int id) { ID = id; }
        bool operator < (const Data& r) const
        {
            return this->id() < r.id();
        }
        bool operator < (const Data* r) const
        {
            return this->id() < r->id();
        }

        explicit Data(Self* view = 0) 
        {
            view_ = view;
        
            ID = -1;
            ID_TABLERECORD = -1;
            ID_CHECKINGACCOUNT = -1;
            TRANSFER = -1;
            ID_CURRENCY = -1;
        }

        explicit Data(wxSQLite3ResultSet& q, Self* view = 0)
        {
            view_ = view;
        
            ID = q.GetInt(0); // ID
            TABLETYPE = q.GetString(1); // TABLETYPE
            ID_TABLERECORD = q.GetInt(2); // ID_TABLERECORD
            ID_CHECKINGACCOUNT = q.GetInt(3); // ID_CHECKINGACCOUNT
            TRANSFER = q.GetInt(4); // TRANSFER
            ID_CURRENCY = q.GetInt(5); // ID_CURRENCY
        }

        Data& operator=(const Data& other)
        {
            if (this == &other) return *this;

            ID = other.ID;
            TABLETYPE = other.TABLETYPE;
            ID_TABLERECORD = other.ID_TABLERECORD;
            ID_CHECKINGACCOUNT = other.ID_CHECKINGACCOUNT;
            TRANSFER = other.TRANSFER;
            ID_CURRENCY = other.ID_CURRENCY;
            return *this;
        }

        template<typename C>
        bool match(const C &c) const
        {
            return false;
        }
        bool match(const Self::ID &in) const
        {
            return this->ID == in.v_;
        }
        bool match(const Self::TABLETYPE &in) const
        {
            return this->TABLETYPE.CmpNoCase(in.v_) == 0;
        }
        bool match(const Self::ID_TABLERECORD &in) const
        {
            return this->ID_TABLERECORD == in.v_;
        }
        bool match(const Self::ID_CHECKINGACCOUNT &in) const
        {
            return this->ID_CHECKINGACCOUNT == in.v_;
        }
        bool match(const Self::TRANSFER &in) const
        {
            return this->TRANSFER == in.v_;
        }
        bool match(const Self::ID_CURRENCY &in) const
        {
            return this->ID_CURRENCY == in.v_;
        }
        wxString to_json() const
        {
            json::Object o;
            this->to_json(o);
            std::wstringstream ss;
            json::Writer::Write(o, ss);
            return ss.str();
        }
        
        int to_json(json::Object& o) const
        {
            o[L"ID"] = json::Number(this->ID);
            o[L"TABLETYPE"] = json::String(this->TABLETYPE.ToStdWstring());
            o[L"ID_TABLERECORD"] = json::Number(this->ID_TABLERECORD);
            o[L"ID_CHECKINGACCOUNT"] = json::Number(this->ID_CHECKINGACCOUNT);
            o[L"TRANSFER"] = json::Number(this->TRANSFER);
            o[L"ID_CURRENCY"] = json::Number(this->ID_CURRENCY);
            return 0;
        }
        row_t to_row_t() const
        {
            row_t row;
            row(L"ID") = ID;
            row(L"TABLETYPE") = TABLETYPE;
            row(L"ID_TABLERECORD") = ID_TABLERECORD;
            row(L"ID_CHECKINGACCOUNT") = ID_CHECKINGACCOUNT;
            row(L"TRANSFER") = TRANSFER;
            row(L"ID_CURRENCY") = ID_CURRENCY;
            return row;
        }
        void to_template(html_template& t) const
        {
            t(L"ID") = ID;
            t(L"TABLETYPE") = TABLETYPE;
            t(L"ID_TABLERECORD") = ID_TABLERECORD;
            t(L"ID_CHECKINGACCOUNT") = ID_CHECKINGACCOUNT;
            t(L"TRANSFER") = TRANSFER;
            t(L"ID_CURRENCY") = ID_CURRENCY;
        }

        /** Save the record instance in memory to the database. */
        bool save(wxSQLite3Database* db)
        {
            if (db && db->IsReadOnly()) return false;
            if (!view_ || !db) 
            {
                wxLogError("can not save TRANSFERTRANS_V1");
                return false;
            }

            return view_->save(this, db);
        }

        /** Remove the record instance from memory and the database. */
        bool remove(wxSQLite3Database* db)
        {
            if (!view_ || !db) 
            {
                wxLogError("can not remove TRANSFERTRANS_V1");
                return false;
            }
            
            return view_->remove(this, db);
        }

        void destroy()
        {
            //if (this->id() < 0)
            //    wxSafeShowMessage("unsaved object", this->to_json());
            delete this;
        }
    };

    enum
    {
        NUM_COLUMNS = 6
    };

    size_t num_columns() const { return NUM_COLUMNS; }

    /** Name of the table*/    
    wxString name() const { return "TRANSFERTRANS_V1"; }

    DB_Table_TRANSFERTRANS_V1() 
    {
        query_ = "SELECT * FROM TRANSFERTRANS_V1 ";
    }

    /** Create a new Data record and add to memory table (cache)*/
    Self::Data* create()
    {
        Self::Data* entity = new Self::Data(this);
        cache_.push_back(entity);
        return entity;
    }
    
    /** Create a copy of the Data record and add to memory table (cache)*/
    Self::Data* clone(const Data* e)
    {
        Self::Data* entity = create();
        *entity = *e;
        entity->id(-1);
        return entity;
    }

    /**
    * Saves the Data record to the database table.
    * Either create a new record or update the existing record.
    * Remove old record from the memory table (cache)
    */
    bool save(Self::Data* entity, wxSQLite3Database* db)
    {
        wxString sql = wxEmptyString;
        if (entity->id() <= 0) //  new & insert
        {
            sql = "INSERT INTO TRANSFERTRANS_V1(TABLETYPE, ID_TABLERECORD, ID_CHECKINGACCOUNT, TRANSFER, ID_CURRENCY) VALUES(?, ?, ?, ?, ?)";
        }
        else
        {
            sql = "UPDATE TRANSFERTRANS_V1 SET TABLETYPE = ?, ID_TABLERECORD = ?, ID_CHECKINGACCOUNT = ?, TRANSFER = ?, ID_CURRENCY = ? WHERE ID = ?";
        }

        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(sql);

            stmt.Bind(1, entity->TABLETYPE);
            stmt.Bind(2, entity->ID_TABLERECORD);
            stmt.Bind(3, entity->ID_CHECKINGACCOUNT);
            stmt.Bind(4, entity->TRANSFER);
            stmt.Bind(5, entity->ID_CURRENCY);
            if (entity->id() > 0)
                stmt.Bind(6, entity->ID);

            stmt.ExecuteUpdate();
            stmt.Finalize();

            if (entity->id() > 0) // existent
            {
                for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
                {
                    Self::Data* e = *it;
                    if (e->id() == entity->id()) 
                        *e = *entity;  // in-place update
                }
            }
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("TRANSFERTRANS_V1: Exception %s, %s", e.GetMessage().c_str(), entity->to_json());
            return false;
        }

        if (entity->id() <= 0)
        {
            entity->id((db->GetLastRowId()).ToLong());
            index_by_id_.insert(std::make_pair(entity->id(), entity));
        }
        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(int id, wxSQLite3Database* db)
    {
        if (id <= 0) return false;
        try
        {
            wxString sql = "DELETE FROM TRANSFERTRANS_V1 WHERE ID = ?";
            wxSQLite3Statement stmt = db->PrepareStatement(sql);
            stmt.Bind(1, id);
            stmt.ExecuteUpdate();
            stmt.Finalize();

            Cache c;
            for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
            {
                Self::Data* entity = *it;
                if (entity->id() == id) 
                {
                    index_by_id_.erase(entity->id());
                    delete entity;
                }
                else 
                {
                    c.push_back(entity);
                }
            }
            cache_.clear();
            cache_.swap(c);
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("TRANSFERTRANS_V1: Exception %s", e.GetMessage().c_str());
            return false;
        }

        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(Self::Data* entity, wxSQLite3Database* db)
    {
        if (remove(entity->id(), db))
        {
            entity->id(-1);
            return true;
        }

        return false;
    }

    template<typename... Args>
    Self::Data* get_one(const Args& ... args)
    {
        for (Index_By_Id::iterator it = index_by_id_.begin(); it != index_by_id_.end(); ++ it)
        {
            Self::Data* item = it->second;
            if (item->id() > 0 && match(item, args...)) 
            {
                ++ hit_;
                return item;
            }
        }

        ++ miss_;

        return 0;
    }
    
    /**
    * Search the memory table (Cache) for the data record.
    * If not found in memory, search the database and update the cache.
    */
    Self::Data* get(int id, wxSQLite3Database* db)
    {
        if (id <= 0) 
        {
            ++ skip_;
            return 0;
        }

        Index_By_Id::iterator it = index_by_id_.find(id);
        if (it != index_by_id_.end())
        {
            ++ hit_;
            return it->second;
        }
        
        ++ miss_;
        Self::Data* entity = 0;
        wxString where = wxString::Format(" WHERE %s = ?", PRIMARY::name().c_str());
        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(this->query() + where);
            stmt.Bind(1, id);

            wxSQLite3ResultSet q = stmt.ExecuteQuery();
            if(q.NextRow())
            {
                entity = new Self::Data(q, this);
                cache_.push_back(entity);
                index_by_id_.insert(std::make_pair(id, entity));
            }
            stmt.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().c_str(), e.GetMessage().c_str());
        }
        
        if (!entity) 
        {
            wxLogError("%s: %d not found", this->name().c_str(), id);
        }
 
        return entity;
    }

    /**
    * Return a list of Data records (Data_Set) derived directly from the database.
    * The Data_Set is sorted based on the column number.
    */
    const Data_Set all(wxSQLite3Database* db, COLUMN col = COLUMN(0), bool asc = true)
    {
        Data_Set result;
        try
        {
            wxSQLite3ResultSet q = db->ExecuteQuery(col == COLUMN(0) ? this->query() : this->query() + " ORDER BY " + column_to_name(col) + " COLLATE NOCASE " + (asc ? " ASC " : " DESC "));

            while(q.NextRow())
            {
                Self::Data entity(q, this);
                result.push_back(entity);
            }

            q.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().c_str(), e.GetMessage().c_str());
        }

        return result;
    }
};
#endif //
