using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace MvcCreditApp.Migrations
{
    /// <inheritdoc />
    public partial class InitialCreateForCredit : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Bids",
                columns: table => new
                {
                    BidId = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Name = table.Column<string>(type: "text", nullable: true),
                    CreditHead = table.Column<string>(type: "text", nullable: true),
                    bidDate = table.Column<DateTime>(type: "timestamp with time zone", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Bids", x => x.BidId);
                });

            migrationBuilder.CreateTable(
                name: "Credits",
                columns: table => new
                {
                    CreditId = table.Column<int>(type: "integer", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Head = table.Column<string>(type: "text", nullable: true),
                    Period = table.Column<int>(type: "integer", nullable: false),
                    Sum = table.Column<int>(type: "integer", nullable: false),
                    Procent = table.Column<int>(type: "integer", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Credits", x => x.CreditId);
                });
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Bids");

            migrationBuilder.DropTable(
                name: "Credits");
        }
    }
}
