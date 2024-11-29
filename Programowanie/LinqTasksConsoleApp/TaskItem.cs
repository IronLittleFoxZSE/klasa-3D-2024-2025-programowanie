using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinqTasksConsoleApp
{
    class TaskItem
    {
        public int TaskId { get; set; }
        public string Name { get; set; }

        public int CategoryId { get; set; }
        public bool IsCompleted { get; set; }

        public override string ToString()
        {
            return $"Id: {TaskId}, Name: {Name}, IsCompleted: {IsCompleted}";
        }
    }
}
